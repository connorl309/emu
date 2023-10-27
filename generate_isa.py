from io import TextIOWrapper
import re
from typing import Dict, List
from bs4 import BeautifulSoup

class instr():
    def __init__(self, opcode: str, len: str, mode: str, flagstring: str, mnemonic: str):
        self.opcode = opcode
        self.len = len
        self.given = mode
        match mode:
            case "(dir,X)":
                self.mode = "direct_x_paren"
            case "stk,S":
                self.mode = "stack_s"
            case "dir":
                self.mode = "direct"
            case "[dir]":
                self.mode = "direct_bracket"
            case "imm":
                self.mode = "immediate"
            case "abs":
                self.mode = "absolute"
            case "long": 
                self.mode = "long_"
            case "(dir),Y":
                self.mode = "direct_paren_y"
            case "(dir)":
                self.mode = "direct_paren"
            case "(stk,S),Y":
                self.mode = "stack_s_paren_y"
            case "dir,X":
                self.mode = "direct_x"
            case "[dir],Y":
                self.mode = "direct_bracket_y"
            case "abs,Y":
                self.mode = "absolute_y"
            case "abs,X":
                self.mode = "absolute_x"
            case "long,X":
                self.mode = "long_x"
            case "(abs)":
                self.mode = "absolute_paren"
            case "[abs]":
                self.mode = "absolute_bracket"
            case "dir,Y":
                self.mode = "direct_y"
            case "rel16":
                self.mode = "rel16"
            case "rel8":
                self.mode = "rel8"
            case "imp":
                self.mode = "implied"
            case "(abs,X)":
                self.mode = "absolute_x_paren"
            case "acc":
                self.mode = "accumulator"
            case "src,dest":
                self.mode = "src_dest"
            case _ : 
                self.mode = "NOT_FOUND_PROVIDED" + mode
        self.flagstring = flagstring
        self.mnemonic = mnemonic
    
    def __str__(self) -> str:
        toRet = ""
        toRet += f"\n\t/*\n\tInstruction: {self.mnemonic.upper()} - mode = '{self.given}'\n\t*/\n\t\tcase 0x{self.opcode}:" + " {\n"
        toRet += f"\t\t\tinstr.opcode = 0x{self.opcode};\n"
        toRet += f"\t\t\tinstr.mnemonic = \"{self.mnemonic.upper()}\";\n"
        if (self.len.find("-") != -1):
            toRet += f"\t\t\tinstr.length = {self.len[0]} - m_flag_val;\n"
        else:
            toRet += f"\t\t\tinstr.length = {self.len[0]};\n"
        toRet += f"\t\t\tinstr.mode = {self.mode};\n"
        toRet += f"\t\t\tinstr.callback = {self.mnemonic.upper()}_execute;\n"
        # tricky part here is flags
        toRet += "\t\t\tinstr.flags_set = {\n"
        funny = "nvmxdizce"
        for i in range(len(funny)):
            if self.flagstring[i] != '.':
                tous = funny[i]
                if (tous == 'x'):
                    tous = "x_b"
                toRet += f"\t\t\t\tstd::pair({funny[i]}_flag, \"{self.flagstring[i]}\"), "
                toRet += f"// {self.mnemonic} instruction sets {funny[i].upper()} flag to {self.flagstring[i].upper()} flag value\n"
        toRet += "\t\t\t};\n"
        # do the same loop for data
        toRet += "\t\t\tfor (uint8_t i = 1; i < instr.length; i++) {\n"
        toRet += "\t\t\t\tinstr.data.push_back(*(memory_address + i));\n"
        toRet += "\t\t\t}\n"
        toRet += "\t\t}"
        return toRet

def printParseCppFile(f: TextIOWrapper, mnem: str):
    f.write("#include \"../../inc/isa.hpp\"\n")
    f.write("#include \"../../inc/isa_impl.hpp\"")
    f.write("\nnamespace snes_cpu {\n\n")
    f.write(f"instruction {mnem.upper()}_parse_instr(uint8_t* memory_address, uint8_t m_flag_val)" + " {\n")
    f.write("\tsnes_cpu::instruction instr;\n\n\tswitch ( *memory_address ) {\n")

GENERATE_PARSE_FILES = True
GENERATE_ISA_TOPLEVEL = True
GENERATE_ISA_IMPL_HEADER = True
GENERATE_ISA_EXECUTE_FUNCS = True

if __name__ == "__main__":
    isa_list: List[instr] = []
    instruction_list = []
    with open("from_web.html") as file:
        soup = BeautifulSoup(file, 'html.parser')
        all_pres = soup.findAll('pre')
        final_list = []
        for s in all_pres:
            s = str(s)
            if (s.find("OP") != -1):
                final_list.append(s.replace("<pre>", "").replace("</pre>", ""))
        #print(helpme)
        # in terms of split-by-whitespace, each line is in order:
        # opcode , length , cycles , mode , flags , e_flag , syntax
        fun = re.compile(r"\s+")
        for line in final_list:
            line = str(line)
            second_newline = line.find("\n", line.find("\n", line.find("\n") + 1) + 1) # strip OP... and ----
            if line.find("OP ") != -1:
                line = line[second_newline+1:].split("\n")
                for i in line:
                    elements = fun.sub(" ", i).strip().split(" ")
                    if (len(elements) == 7 or len(elements) == 8):
                        isa_list.append(instr(opcode=elements[0], len=elements[1], mode=elements[3], flagstring=elements[4] + elements[5], mnemonic=elements[6]))
                        if (elements[6] not in instruction_list):
                            instruction_list.append(elements[6])
        
        # Generate every instruction's parse/X_parse.cpp file
        if (GENERATE_PARSE_FILES):
            outputter = None
            last_instr = ""
            for i in isa_list:
                # create and init file if needed
                if last_instr != i.mnemonic:
                    if outputter is not None:
                        outputter.write("\n\t}\n\treturn instr;\n\t}\n}")
                        outputter.close()
                    last_instr = i.mnemonic
                    outputter = open("./src/snes/cpu/parse/" + i.mnemonic.upper() + "_parse.cpp", mode='w')
                    printParseCppFile(outputter, last_instr)
                    outputter.write(str(i))
                else:
                    outputter.write(str(i))
            # final cleanup
            outputter.write("\n\t}\n\treturn instr;\n\t}\n}")
            outputter.close()
        # Generate the isa.cpp file
        # Note: the opcode map generated must match the parse_ function names in the if() statement after this one
        if (GENERATE_ISA_TOPLEVEL):
            outputter = None
            mnemonic_map: Dict[str, str] = {}
            outputter = open("./src/snes/cpu/isa.cpp", "w+")
            outputter.write("#include \"../inc/isa.hpp\"\n#include \"../inc/isa_impl.hpp\"\n#include <map>\n\n")
            outputter.write("namespace snes_cpu {\n\n")
            outputter.write("// May not be needed.\nstatic const std::map<uint8_t, std::function<void(uint8_t*, uint8_t)>> opc_to_mnemonic = {\n")
            ctr = 0
            for i in isa_list:
                mnemonic_map[str(i.opcode)] = i.mnemonic.upper()
                outputter.write("\t{0x" + i.opcode + "," + i.mnemonic.upper() + "_parse_instr}, ")
                ctr += 1
                if (ctr == 8):
                    outputter.write("\n")
                    ctr = 0
            outputter.write("};\n") # end mnemonic map
            outputter.write("\ninstruction parseInstruction(uint8_t* memory_address, uint8_t m_flag_val) {\n")
            outputter.write("\tinstruction instr;\n\tswitch ( *memory_address ) {\n")
            last_instr = ""
            outputter.write("\t}\n")
            #for i in mnemonic_map.keys():
            
            outputter.write("\treturn instr;\n}\n\n")
            outputter.write("}")
            outputter.close()
        # Generate isa_impl.hpp declarations
        if (GENERATE_ISA_IMPL_HEADER):
            outputter = open("./src/snes/inc/isa_impl.hpp", "w+")
            outputter.write("#ifndef ISA_IMPL_HPP\n#define ISA_IMPL_HPP\n#include \"isa.hpp\"\n")
            outputter.write("\nnamespace snes_cpu {\n")
            for i in instruction_list:
                outputter.write(f"\n\t// Parse and execute a {str(i).upper()} instruction from starting memory address\n")
                outputter.write(f"\tinstruction {str(i).upper()}_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);\n")
                outputter.write(f"\tvoid {str(i).upper()}_execute(cpu_registers& regfile);\n")
            outputter.write("\n}\n#endif")
            outputter.close()
        # Generate the execute file
        if (GENERATE_ISA_EXECUTE_FUNCS):
            outputter = open("./src/snes/cpu/isa_execute.cpp", "w+")
            outputter.write("#include \"../inc/isa.hpp\"\n#include \"../inc/isa_impl.hpp\"")
            outputter.write("\n\nnamespace snes_cpu {\n")
            for i in instruction_list:
                outputter.write(f"\n\tvoid {str(i).upper()}_execute(cpu_registers& regfile) " + "{\n\n\t}\n")
            outputter.write("\n}")
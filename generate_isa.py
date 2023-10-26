import re
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
        toRet += f"/*\n\tInstruction: {self.mnemonic.upper()} - mode = '{self.given}'\n*/\ncase 0x{self.opcode}:" + " {\n"
        toRet += f"\tinstr.opcode = 0x{self.opcode};\n"
        toRet += f"\tinstr.mnemonic = \"{self.mnemonic.upper()}\";\n"
        toRet += f"\tinstr.length = {self.len[0]} - m_val;\n"
        toRet += f"\tinstr.mode = {self.mode};\n"
        # tricky part here is flags
        toRet += "\tinstr.flags_set = {\n"
        funny = "nvmxdizce"
        for i in range(len(funny)):
            if self.flagstring[i] != '.':
                tous = funny[i]
                if (tous == 'x'):
                    tous = "x_b"
                toRet += f"\t\tstd::pair({funny[i]}_flag, \"{self.flagstring[i]}\"), "
                toRet += f"// {self.mnemonic} instruction sets {funny[i].upper()} flag to {self.flagstring[i].upper()} flag value\n"
        toRet += "\t};\n"
        # do the same loop for data
        toRet += "\tfor (uint8_t i = 0; i < instr.length - m_val; i++) {\n"
        toRet += "\t\tinstr.data.push_back(*(memory_address + i + 1));\n"
        toRet += "\t}\n"
        toRet += "}"
        return toRet

if __name__ == "__main__":
    isa_list = []
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
        
        for i in isa_list:
            print(i)
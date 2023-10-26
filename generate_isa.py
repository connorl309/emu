class instr():
    def __init__(self, opcode, len, mode, flagstring, mnemonic):
        self.opcode = opcode
        self.len = len
        match mode:
            case "(dir,X)":
                self.mode = "direct_x_paren"
            case "(stk,S)":
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
            case "(dir),Y":
                pass
            case _ : 
                pass
        self.flagstring = flagstring
        self.mnemonic = mnemonic

if __name__ == "__main__":
    with open("from_web.txt") as file:

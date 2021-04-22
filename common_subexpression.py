f = open("TAC.txt","r")
opt = open("common_sub.txt", "w")
list_of_lines = f.readlines()

hold = {}
for i in list_of_lines:
    if "function"  in i:
        pass
    else:
        i = i.strip("\n")
        op,arg1,arg2,res = i.split()
        result = op + arg1 + arg2 
        if result in hold:
            pointer = hold.get(result)
            print(pointer)
            write_back = op+" "+arg1+" "+arg2+" "+pointer+"\n"
            opt.write(write_back)
        else:
            hold[result] = res
            write_back = op+" "+arg1+" "+arg2+" "+res+"\n"
            opt.write(write_back)


        

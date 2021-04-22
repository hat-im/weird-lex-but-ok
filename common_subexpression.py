f = open("TAC.txt","r")
opt = open("common_sub.txt", "w")
list_of_lines = f.readlines()
re_written_res="temp"
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
            re_written_res = res
            write_back = op+" "+arg1+" "+arg2+" "+pointer+"\n"
            opt.write(write_back)
        else:
            hold[result] = res
            write_back = op+" "+arg1+" "+arg2+" "+res+"\n"
            opt.write(write_back)
        
        for j in  hold.items():
            if re_written_res in j:
                write_back = op+" "+re_written_res+" "+arg2+" "+res+"\n"
                print(write_back)
                opt.write(write_back)

print(hold,"\n")
print(pointer,"\n")
print(re_written_res)
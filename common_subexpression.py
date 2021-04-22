
f = open("TAC.txt","r")
opt = open("common_sub.txt", "w")
list_of_lines = f.readlines()
re_written_res="temp"
hold = {}
writen=0
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
            writen=1
            
            # write_back = op+" "+arg1+" "+arg2+" "+pointer+"\n"
            # opt.write(write_back)
    #op+" "+arg1+" "+arg2+" "+res+"\n"  "="+" "+arg1+" "+"NULL"+" "+res+"\n"
                          
        else:
            hold[result] = res
            if writen==1:
                write_back = op+" "+pointer+" "+arg2+" "+res+"\n"
                writen=0
            else:
                write_back = op+" "+arg1+" "+arg2+" "+res+"\n"
            
            opt.write(write_back)
            
            
 
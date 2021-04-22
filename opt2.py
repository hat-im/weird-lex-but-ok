f = open("TAC.txt","r")
fout = open("out.txt","w")
ftemp = open("temp.txt","w")

list_of_lines = f.readlines()
dictValues = dict()
constantFoldedList = []
print("Quadruple form after Constant Folding")
print("-------------------------------------")
for i in list_of_lines:
    if "function" in i:
        pass
    else:
        i = i.strip("\n")
        op,arg1,arg2,res = i.split()
        if(op in ["+","-","*","/"]):
            if(arg1.isdigit() and arg2.isdigit()):
                result = eval(arg1+op+arg2)
                dictValues[res] = result
                print("=",result,"NULL",res)
                write_back="="+" "+result+" "+"NULL"+" "+res+"\n"
                ftemp.write(write_back)
                constantFoldedList.append(["=",result,"NULL",res])
            elif(arg1.isdigit()):
                if(arg2 in dictValues):
                    result = eval(arg1+op+dictValues[arg2])
                    dictValues[res] = result
                    print("=",result,"NULL",res)
                    write_back="="+" "+result+" "+"NULL"+" "+res+"\n"
                    ftemp.write(write_back)
                    constantFoldedList.append(["=",result,"NULL",res])
                else:
                    print(op,arg1,arg2,res)
                    write_back=op+" "+arg1+" "+arg2+" "+res+"\n"
                    ftemp.write(write_back)
                    constantFoldedList.append([op,arg1,arg2,res])
            elif(arg2.isdigit()):
                if(arg1 in dictValues):
                    result = eval(dictValues[arg1]+op+arg2)
                    dictValues[res] = result
                    print("=",result,"NULL",res)
                    write_back="="+" "+result+" "+"NULL"+" "+res+"\n"
                    ftemp.write(write_back)
                    constantFoldedList.append(["=",result,"NULL",res])
                else:
                    print(op,arg1,arg2,res)
                    write_back=op+" "+arg1+" "+arg2+" "+res+"\n"
                    ftemp.write(write_back)
                    constantFoldedList.append([op,arg1,arg2,res])
            else:
                flag1=0
                flag2=0
                arg1Res = arg1
                if(arg1 in dictValues):
                    arg1Res = str(dictValues[arg1])
                    flag1 = 1
                arg2Res = arg2
                if(arg2 in dictValues):
                    arg2Res = str(dictValues[arg2])
                    flag2 = 1
                if(flag1==1 and flag2==1):
                    result = eval(arg1Res+op+arg2Res)
                    dictValues[res] = result
                    print("=",result,"NULL",res)
                    write_back="="+" "+result+" "+"NULL"+" "+res+"\n"
                    ftemp.write(write_back) 
                    constantFoldedList.append(["=",result,"NULL",res])
                else:
                    print(op,arg1Res,arg2Res,res)
                    write_back=op+" "+arg1Res+" "+arg2Res+" "+res+"\n"
                    ftemp.write(write_back)
                    constantFoldedList.append([op,arg1Res,arg2Res,res])
            
        elif(op=="="):
            if(arg1.isdigit()):
                dictValues[res]=arg1
                print("=",arg1,"NULL",res)
                write_back="="+" "+arg1+" "+"NULL"+" "+res+"\n"
                ftemp.write(write_back)
                constantFoldedList.append(["=",arg1,"NULL",res])
            else:
                if(arg1 in dictValues):
                    print("=",dictValues[arg1],"NULL",res)
                    write_back="="+" "+dictValues[arg1]+" "+"NULL"+" "+res+"\n"
                    ftemp.write(write_back)
                    constantFoldedList.append(["=",dictValues[arg1],"NULL",res])
                else:
                    print("=",arg1,"NULL",res)
                    write_back="="+" "+arg1+" "+"NULL"+" "+res+"\n"
                    ftemp.write(write_back)
                    constantFoldedList.append(["=",arg1,"NULL",res])
        
        else:
            print(op,arg1,arg2,res)
            write_back=op+" "+arg1+" "+arg2+" "+res+"\n"
            ftemp.write(write_back)
            constantFoldedList.append([op,arg1,arg2,res])
ftemp.close()
print("\n")
print("Constant folded expression - ")
print("--------------------")
for i in constantFoldedList:
    if(i[0]=="="):
        print(i[3],i[0],i[1])
    elif(i[0] in ["+","-","*","/","==","<=","<",">",">="]):
        print(i[3],"=",i[1],i[0],i[2])
    elif(i[0] in ["if","goto","label","not"]):
        if(i[0]=="if"):
            print(i[0],i[1],"goto",i[3])
        if(i[0]=="goto"):
            print(i[0],i[3])
        if(i[0]=="label"):
            print(i[3],":")
        if(i[0]=="not"):
            print(i[3],"=",i[0],i[1])


print("\n")
print("After dead code elimination - ")
print("------------------------------")
flip = open("temp.txt","r")
opt = open("common_sub.txt", "w")
list_of_lines = flip.readlines()
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
            
                          
        else:
            hold[result] = res
            if writen==1:
                write_back = op+" "+pointer+" "+arg2+" "+res+"\n"
                print(write_back)
                writen=0
            else:
                write_back = op+" "+arg1+" "+arg2+" "+res+"\n"
                print(write_back)
            
            opt.write(write_back)
 



print("\n")
print("After dead code elimination - ")
print("------------------------------")
for i in constantFoldedList:
    if(i[0]=="="):
        pass
    elif(i[0] in ["+","-","*","/","==","<=","<",">",">="]):
        print(i[3],"=",i[1],i[0],i[2])
    elif(i[0] in ["if","goto","label","not"]):
        if(i[0]=="if"):
            print(i[0],i[1],"goto",i[3])
        if(i[0]=="goto"):
            print(i[0],i[3])
        if(i[0]=="label"):
            print(i[3],":")
        if(i[0]=="not"):
            print(i[3],"=",i[0],i[1])
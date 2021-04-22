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
        op,arg1,arg2,res=i.split()
        
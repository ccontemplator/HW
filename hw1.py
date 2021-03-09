import csv

def avg(c):
    total=0.0
    for i in range(0,len(c)):
        total+=c[i]
    return total/float(len(c))
    

C=[[],[],[],[],[]]



with open('108061173.csv',"r") as csv_file:
    csv_reader=csv.reader(csv_file)
    next(csv_reader)
    for line in csv_reader:       
        #print(line[7])
        if line[7] == '-99.000' or line[7] == '-999.000' :
            continue

        if line[0]=="C0A880":
            C[0].append(float(line[7]))
        if line[0]=="COF9A0":
            C[1].append(float(line[7]))
        if line[0]=="C0G640":
            C[2].append(float(line[7]))
        if line[0]=="C0R190":
            C[3].append(float(line[7]))
        if line[0]=="C0X260":
            C[4].append(float(line[7]))           

output=[]

output.extend((["C0A880"],["COF9A0"],["C0G640"],["C0R190"],["C0X260"]))

for i in range(0,5):
    if len(C[i]) != 0:
        output[i].append(avg(C[i]))
    else:
        output[i].append("None")


print(output)

  
        




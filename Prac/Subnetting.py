import math

def findClass(hob) :
    if hob < 128 :
        return "A", "255.0.0.0", 8
    elif hob < 192 :
        return "B", "255.255.0.0", 16
    elif hob < 224 :
        return "C", "255.255.255.0", 24
    elif hob < 240 :
        return "D", "255.255.255.255", 32
    else :
        return "E"

def subnetting(cls, ip, sub, hosts) :
    temp = 0
    if cls[0] == "C" :
        for i in range(sub) :
            hostId = ".".join(ip[0:3])
            print("\nsubnet no :" + str(i+1))
            print("subnet address :"+ hostId + "." + str(temp))
            print("Valid range :" + hostId + "."+ str(temp+1))
            temp = int(temp + hosts)
            print(" to " + hostId +"."+ str(temp-2))
            print("broadcast :" + hostId +"."+ str(temp-1))



inp = input()
inp = inp.split(".")
ip = [int(i) for i in inp]

Class = findClass(ip[0])

print(Class)

noOfSubn = 4
noOfBits = math.log(noOfSubn,2)
noOfHost = 2 ** (32- Class[2]- noOfBits)

print (noOfHost)

subnetting(Class, inp, noOfSubn, noOfHost)



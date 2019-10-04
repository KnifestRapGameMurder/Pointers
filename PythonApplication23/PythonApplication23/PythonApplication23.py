#import random
#user_answer = int(input("угадай число"))
#random = random.randrange(0,10,1)
#if user_answer == random:
 #   print("ты угадал")
#else:
   # print("ты не угадал")
 #  name = input("enter your name")
 #  used_registered_name = "Anton"
 #  if name == used_registered_name or name.capitalize() == used_registered_name:
   #    print("privet "+used_registered_name)
  #     if name.capitalize() == used_registered_name: 

#a = 3
#b = 5.56
#c = "hi"

#list = [a,b,c]
#print(list[1:])
#print(list)
#list.append("asughj")
#list[3] = 2
#list.insert(3,"world")
#print(list)
#list.remove("hi")
#print(list)
#list.pop(1)
#print(list)
#list_of_numbers = [a,b,9,8,999,0]
#print(list_of_numbers)
#list_of_numbers.reverse()
#print(list_of_numbers)
#list_of_numbers.sort()
#print(list_of_numbers)



##list_of_subjects= ["eng","math","ukr","Pe","hist","bio","wrl","info"]
##monday = (list_of_subjects[2],list_of_subjects[1],list_of_subjects[3])
##print(monday)
##tuesday = (list_of_subjects[0],list_of_subjects[5],list_of_subjects[7])
##print(tuesday)
##wednesday = (list_of_subjects[3],list_of_subjects[6],list_of_subjects[4])
##print(wednesday)

#a = set()
#print(type(a))
#set_1 = {1,2,3,4,5,5,6}
#set_2 = {1,2,4,5,7,12}
#result = set_1 & set_2
#result = set_1 | set_2
#print(result)


#dict = {1:"one",2:"two"}
#print(dict[1])
#print(dict)


thursday = ["math","engl","chemis","ukr","literat"]
dict_thursday = {thursday[0]:1,thursday[1]:2,thursday[2]:3,thursday[3]:4,thursday[4]:5}
#print(thursday[1]+" -> "+str(dict_thursday[thursday[1]]))
#print(thursday[2]+" -> "+str(dict_thursday[thursday[2]]))
#print(thursday[3]+" -> "+str(dict_thursday[thursday[3]]))
#print(thursday[4]+" -> "+str(dict_thursday[thursday[4]]))

for i in range(len(thursday)):
   
    print(thursday[i]+" -> "+str(dict_thursday[thursday[i]]))

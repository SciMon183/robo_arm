#this is sample of code on my new project with i do 

# this section chesc is program request and interaction with a user
# in future this section s automaticly skip 
print("Hello this is a basic message with this program return if it starts")
print("If you see this message thats mean the file work and pras the 'y' and press enter to continue")

confim = str(input())

if confim == 'y':
    print("you press 'y' so we continue with the process")
    work = True
else:
    print("so the program is not working good")
    work = False
    
# this section strt workin on actualy project 

while work is True: 
    print("hello world")
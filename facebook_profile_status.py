class user:
    name=''
    email=''
    passwrd=''
    def lgin(self):
        email=input("enter the email: ")
        passwrd=input("enter passwrd: ")
        
        if email==self.email and passwrd==self.passwrd:
            print('ok')
        else:
            print('No')
    def logout(self):
        login=False
        print('log out')
    def loggedin(self):
        if self.login:
            return True
        else:
            return False
    def pr(self):
        if self.loggedin:
            print(self.name,' ',self.email)
        else:
            print('somthing error')


user1=user()
user1.name="Naim reza"
user1.email='naimreza@gmail.com'
user1.passwrd="12234"
user1.lgin()
user1.pr()
user1.logout()
user1.pr()
        
        
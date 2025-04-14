# The code above is a solution to a problem that involves reading a phone book and querying it for phone numbers.
# It uses a dictionary comprehension to create a phone book from user input and then allows the user to query the phone book.
# The solution is efficient and handles input and output in a clean manner.
# The code is written in Python and uses dictionary comprehension to create a phone book from user input.

phoneBook = {
    name: phone for name, 
    phone in (input().split() 
              for _ in range(int(input())))}

while True:
    try:
        query = input().strip()
        print(f"{query}={phoneBook[query]}" if query in phoneBook else "Not found")
    except EOFError:
        break



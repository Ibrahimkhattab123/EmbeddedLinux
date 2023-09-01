import webbrowser

favourite_websites = {
    "Google": "https://www.google.com",
    "Youtube": "https://www.youtube.com",
    "GitHub": "https://www.github.com/Ibrahimkhattab123",
    "LinkedIn": "https://www.linkedin.com/in/ibrahim-khattab/"
}

def open_website(site_name):
    if site_name in favourite_websites:
        url = favourite_websites[site_name]
        webbrowser.open(url)
    else:
        print("Website not found in favourite list")

def main():
    while True:
        print("\nFavourite List: ")
        for site in favourite_websites:
            print(site)
        choice = input("Enter the name of the website, please ")
        if choice.lower == 'exite':
            print("Goodbye!")

        open_website(choice)

if __name__ == "__main__":
    main()
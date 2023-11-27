import random
import requests


def suggest_activity():
    activities = [
        {
            "activity": "Have a photo session with some friends",
            "type": "social",
            "participants": 4,
            "price": 0.05,
            "link": "",
            "key": "3305912",
            "accessibility": 0.8,
        },
        {
            "activity": "Go for a hike in a nearby park",
            "type": "outdoor",
            "participants": 2,
            "price": 0,
            "link": "",
            "key": "1234567",
            "accessibility": 0.5,
        },
        {
            "activity": "Read a book you've been wanting to start",
            "type": "indoor",
            "participants": 1,
            "price": 0,
            "link": "",
            "key": "9876543",
            "accessibility": 0.2,
        },
        {
            "activity": "Cook a new recipe for dinner",
            "type": "culinary",
            "participants": 2,
            "price": 0.2,
            "link": "",
            "key": "4567890",
            "accessibility": 0.6,
        },
    ]

    suggestion = random.choice(activities)
    return suggestion


def get_public_ip():
    try:
        response = requests.get("https://api64.ipify.org?format=json")
        if response.status_code == 200:
            ip_data = response.json()
            return ip_data.get("ip")
        else:
            return "Unable to retrieve public IP."
    except Exception as e:
        return str(e)


def main():
    activity_suggestion = suggest_activity()
    public_ip = get_public_ip()

    print("Activity Suggestion:")
    print(activity_suggestion)

    print("\nYour Public IP Address:")
    print(public_ip)


if __name__ == "__main__":
    main()

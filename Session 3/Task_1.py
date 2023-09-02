import pyautogui
import time 

def open_and_mark_email_as_read():
    pyautogui.hotkey('ctrl', 'alt', 't')
    time.sleep(1)
    pyautogui.write('thunderbird')
    pyautogui.press('enter')

    time.sleep(10)


    #email_pos = (100, 200)
    #pyautogui.click(email_pos)

    #mark_as_read_pos = (300, 400)
    #pyautogui.click(mark_as_read_pos)

    pyautogui.hotkey('ctrl', 'q')

def main():
    open_and_mark_email_as_read()

if __name__ == "__main__":
    main()
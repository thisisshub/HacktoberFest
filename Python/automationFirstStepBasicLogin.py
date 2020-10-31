from selenium import webdriver

from selenium.webdriver.common.by import By

import time
from selenium.webdriver.support.select import Select

# Make sure your driver has the right path
driver = webdriver.Chrome('Python\chromedriver.exe')

driver.maximize_window()

# Add the web url you war to get in in chrome browser 
driver.get("HERE_PUT_THE_URL_YOU_WANT_GET_IN")
time.sleep(3)

# Add a selector for email field
email = driver.find_element(By.XPATH, "HERE_PUT_EMAIL_FIELD_SELECTOR")
# Set your email
email.send_keys("angelangel10050@gmail.com")

# Add a selector for password field
password = driver.find_element(By.XPATH, "HERE_PUT_PASSWORD_FIELD_SELECTOR")
# Set your password
password.send_keys("example123") 

# Add a selector for login button (Here we are executing click action too)
login = driver.find_element(By.XPATH, "//a[@class='btn btn-block btn-primary mb-20']").click()
time.sleep(50)

# We clone the program
driver.close()
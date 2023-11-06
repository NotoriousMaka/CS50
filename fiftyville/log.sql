-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28;

SELECT name, transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE "%bakery%";

SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25;

--license plate search
SELECT people.name, bakery_security_logs.license_plate, bakery_security_logs.hour, bakery_security_logs.minute
FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND
bakery_security_logs.day = 28 AND bakery_security_logs.hour = 10 AND
bakery_security_logs.minute BETWEEN 15 AND 25;

--bruce @ ATM
SELECT * from atm_transactions WHERE atm_location = "Leggett Street"
AND year = 2021 AND month = 7 AND day = 28;

SELECT atm_transactions.*, people.name FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE atm_transactions.atm_location = "Leggett Street" AND atm_transactions.year = 2021 AND
atm_transactions.month = 7 AND atm_transactions.day = 28 AND
atm_transactions.transaction_type = "withdraw";

--phone calls
SELECT * FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28;

--phone calls under one hour
SELECT * FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND phone_calls.duration < 60;

--find names of each caller
SELECT people.name, phone_calls.caller, phone_calls.year, phone_calls.month, phone_calls.day, phone_calls.duration
FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration < 60;

--flights out of fiftyville
SELECT flights.*, origin_airport_id, destination_airport_id FROM flights
JOIN airports origin ON flights.origin_airport_id = origin.id
JOIN airports destination ON flights.destination_airport_id = destination.id
WHERE origin.id = 8 AND
flights.year = 2021 AND flights.month = 7 AND flights.day = 29;

--put it all together
SELECT people.name FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute BETWEEN 15 AND 25
AND atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw"
AND phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration < 60;

--find the receiver of the number Burce called
SELECT caller.name, pc.caller, pc.receiver, receiver.name, pc.duration FROM phone_calls
JOIN phone_calls pc
JOIN people caller ON pc.caller = caller.phone_number
JOIN people receiver ON pc.receiver = receiver.phone_number
WHERE caller.name = "Bruce" AND pc.year = 2021
AND pc.month = 7 AND pc.day = 28
AND pc.duration < 60;

BTW TIME 00:01:45
HAI 1.4

CAN HAS STDIO?
CAN HAS STRING?

BTW Initialize the input sequence of digits
I HAS A input ITZ "input lmao"

BTW Initialize the sum to 0
I HAS A sum ITZ 0

BTW Get the length of the input
I HAS A length
length R I IZ STRING'Z LEN YR input MKAY

BTW Calculate the halfway point
I HAS A halfway ITZ QUOSHUNT OF length AN 2

BTW Iterate through the input sequence
I HAS A i ITZ 0
IM IN YR LOOP
    BTW Get the current digit
    I HAS A current_digit ITZ I IZ STRING'Z AT YR input AN YR i MKAY

    BTW Get the halfway index (circular)
    I HAS A halfway_index ITZ SUM OF i AN halfway
    halfway_index R MOD OF halfway_index AN length

    BTW Get the halfway digit
    I HAS A halfway_digit ITZ I IZ STRING'Z AT YR input AN YR halfway_index MKAY

    BTW Compare the current digit with the halfway digit
    BOTH SAEM current_digit AN halfway_digit, O RLY?
        YA RLY
            BTW Add the current digit to the sum
            sum R SUM OF sum AN current_digit
        NO WAI
            BTW Do nothing
    OIC

    BTW Increment the index
    i R SUM OF i AN 1

    BTW Check if we should exit the loop
    BOTH SAEM i AN length, O RLY?
        YA RLY
            BTW Exit the loop
            GTFO
        NO WAI
            BTW Continue the loop
    OIC
IM OUTTA YR LOOP

BTW Output the result
VISIBLE sum

KTHXBYE
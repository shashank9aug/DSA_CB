/*
    Word-Break-II : we have given string and dictionary of words to validate sentence words 

    we have to generate all the substrings and validate them from dictionary and add space in between words 
    and return as set of all possible sentences  

    I/P: Input: s = "catsanddog", n = 5 
    
    dict = {"cats", "cat", "and", "sand", "dog"}
    
    Output: 
    (cats and dog)
    (cat sand dog) 

    Approach : Break in to substrings and validate using DP and undo the step as back tracking to check 
    other sentence possibility .

*/


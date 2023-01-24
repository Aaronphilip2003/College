; if you give an input 45 it will be entered as [34,35,"ascii value of enter key"],
; ASCII value of 4 is 34
; ASCII value of 5 is 35
; if you press enter the ASCII value of the enter key will also get saved
; we need to convert 34 and 35 to 4 and 5
; rotate operation is performed bit by bit
; rotate 04 we will get 40 then add 5
; steps first subtract 30 or 37, then rotate the higher digit and add the lower digit
; 34 35 --> 04, 05 -->rotate higher bit ---> 40,05---> add them ----> therefore ans is 45



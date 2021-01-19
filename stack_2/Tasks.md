# Tasks

## 1.Next Greater Element

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:

For any array, rightmost element always has next greater element as -1.
For an array which is sorted in decreasing order, all elements have next greater element as -1.
For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
```
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
```

For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.
```

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1
```
## 2.Prefix to Postfix

Prefix: An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2). 
```
Example : *+AB-CD (Infix : (A+B) * (C-D) )
```

Postfix: An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator).
```
Example : AB+CD-* (Infix : (A+B * (C-D) )
```
Given a Prefix expression, convert it into a Postfix expression.

## 3.Prefix to Postfix

Given a Postfix expression, convert it into a Prefix expression.
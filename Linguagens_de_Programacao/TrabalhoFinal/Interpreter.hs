module Interpreter where 

import Lexer
import Parser

isValue :: Expr -> Bool
isValue BTrue   = True
isValue BFalse  = True
isValue (Num _) = True
isValue _       = False

step :: Expr -> Expr
step (Add (Num n1) (Num n2)) = Num (n1 + n2)
step (Add (Num n) e) = Add (Num n) (step e)
step (Add e1 e2) = Add (step e1) e2
step (Sub (Num n1) (Num n2)) = Num (n1 - n2)
step (Sub (Num n) e) = Sub (Num n) (step e)
step (Sub e1 e2) = Sub (step e1) e2
step (Mul (Num n1) (Num n2)) = Num (n1 * n2)
step (Mul (Num n) e) = Mul (Num n) (step e)
step (Mul e1 e2) = Mul (step e1) e2
step (And BFalse _) = BFalse
step (And BTrue e) = e
step (And e1 e2) = And (step e1) e2
step (Or BTrue _) = BTrue
step (Or _ BTrue) = BTrue
step (Or BFalse e) = e
step (Or e BFalse) = e
step (Or e1 e2) = Or (step e1) e2 
step (If BFalse e1 e2) = e2
step (If BTrue e1 e2) = e1
step (If e e1 e2) = If (step e) e1 e2
step e = e

eval :: Expr -> Expr
eval e | isValue e = e
       | otherwise = eval (step e)
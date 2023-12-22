module TypeChecker where 

import Lexer 
import Parser
import Interpreter

type Ctx = [(String,Ty)]

typeof :: Ctx -> Expr -> Maybe Ty 
typeof ctx BTrue = Just TBool 
typeof ctx BFalse = Just TBool 
typeof ctx (Num _) = Just TNum 
typeof ctx (Add e1 e2) = case (typeof ctx e1, typeof ctx e2) of 
                       (Just TNum, Just TNum) -> Just TNum 
                       _                      -> Nothing


typeof ctx (Sub e1 e2) = case (typeof ctx e1, typeof ctx e2) of
                        (Just TNum, Just TNum) -> Just TNum
                        _                      -> Nothing

typeof ctx (Mul e1 e2) = case (typeof ctx e1, typeof ctx e2) of
                        (Just TNum, Just TNum) -> Just TNum
                        _                      -> Nothing 

typeof ctx (And e1 e2) = case (typeof ctx e1, typeof ctx e2) of 
                       (Just TBool, Just TBool) -> Just TBool 
                       _                        -> Nothing
typeof ctx (If e1 e2 e3) = case typeof ctx e1 of 
                         Just TBool -> case (typeof ctx e2, typeof ctx e3) of
                                         (Just t1, Just t2)       -> if (t1 == t2) then
                                                                       Just t1 
                                                                     else 
                                                                       Nothing
                                         _                        -> Nothing
                         _          -> Nothing
typeof ctx (Paren e) = typeof ctx e
typeof ctx (Var x) = lookup x ctx 
typeof ctx (Lam v t1 b) = let ctx' = (v, t1):ctx 
                            in case typeof ctx' b of 
                                 Just t2 -> Just (TFun t1 t2)
                                 _       -> Nothing
typeof ctx (App e1 e2) = case (typeof ctx e1, typeof ctx e2) of 
                           (Just (TFun t11 t12), Just t2) -> if (t11 == t2) then 
                                                               Just t12
                                                             else 
                                                               Nothing 
                           _  -> Nothing
typeof ctx (Let v e1 e2) = case typeof ctx e1 of 
                             Just t1 -> typeof ((v, t1):ctx) e2 
                             _       -> Nothing 


-- Adicionado Tratamento para verificação do while, sendo que e1 é o condicional e e2 é o corpo 
typeof ctx (While e1 e2) = if typeof ctx e1 == Just TBool && typeof ctx e2 == Just TBool
                            then Just TBool
                            else Nothing


typecheck :: Expr -> Expr 
typecheck e = case typeof [] e of 
                Just _ -> e 
                _      -> error "Type error!"
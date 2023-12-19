{
module Parser where
import Lexer
}

%name parser
%tokentype { Token }
%error { parseError }

%token
    num             { TokenNum $$ }
    '+'             { TokenAdd }
    "-"             { TokenSub }
    "*"             { TokenMul }
    "&&"            { TokenAnd }
    true            { TokenTrue }
    false           { TokenFalse }
    if              { TokenIf }
    then            { TokenThen }
    else            { TokenElse } 
    "||"            { TokenOr }


%left '+'

%%

Exp                 : num                           { Num $1 }
                    | true                          { BTrue }
                    | false                         { BFalse }
                    | Exp '+' Exp                   { Add $1 $3 }
                    | Exp "-" Exp                   { Sub $1 $3 }
                    | Exp "*" Exp                   { Mul $1 $3 }
                    | Exp "&&" Exp                  { And $1 $3 }
                    | if Exp then Exp else Exp      { If $2 $4 $6 }
                    | Exp "||" Exp                  { Or $1 $3 }
                
{

parseError :: [Token] -> a
parseError _ = error "Syntaxe error!"

}
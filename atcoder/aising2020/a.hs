
noprint :: IO a -> () -- replならこの行は不要
noprint x = ()
noprint $ putStrLn "hello, hukusayou!"

return :: a -> m a
(>>=) :: m a -> (a -> m b) -> m b

(return x) >>= f = f x -- x :: a, f :: a -> m b
y >>= return     = y   -- y :: m a
(y >>= f)  >>= g = y >>= (\x -> f x >>= g)  
-- y :: m a, f :: a -> m b, g :: b ->m c

(>>=’) :: a -> m b -> (b -> m c) -> a -> m c
f >>=' g = \x -> f x >>= g

put :: s -> v -> s
get :: s -> v

p s (g s) = s
g (p s v) = v

main :: IO ()
main = do
  input <- read_
  
  unless (input == ":quit")
       $ print_ (eval_ input) >> main

{-# LANGUAGE FlexibleContexts #-}
import Control.Applicative hiding (many)
import Text.Parsec hiding ((<|>))

data Formula = Add Formula Formula
              | Sub Formula Formula
              | Mul Formula Formula
              | Val Integer
              deriving Show

symbol xs = do
  result <- string xs
  spaces
  return result

op1 = (const Mul <$> symbol "*")
op2 = (const Add <$> symbol "+") <|> (const Sub <$> symbol "-")

num = do
  xs <- read <$> many1 digit :: Stream s m Char => ParsecT s u m Integer
  return $ Val xs 

parens = do
  symbol "("
  result <- expr
  symbol ")"
  return result

term = try parens <|> num
expr = do
  spaces
  term `chainl1` op1 `chainl1` op2 


main :: IO ()
main = do
  formula <- getLine
  let result = parse expr "" formula
  putStrLn $ either show show result
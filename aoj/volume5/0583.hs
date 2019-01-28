import Control.Applicative
import Text.Printf
import Debug.Trace

gcd_n :: [Integer]->Integer
gcd_n l = foldl gcd 0 l 

divisors :: Integer -> [Integer]
divisors n = let smalls = [x |x<-[1..(min n 100000)], x*x<=n && mod n x == 0] in
                            if n==(last smalls)^2 then smalls ++ [div n x| x<-tail $ reverse smalls]
                            else smalls ++ [div n x| x<-reverse smalls]

solve :: [Integer]->[Integer]
solve a = divisors $ gcd_n a

listToStrings :: [Integer]->String
listToStrings [] = ""
listToStrings (x:xs) = ((show x)++"\n")++(listToStrings xs)

main :: IO ()
main = do
  n <- getLine
  nums <- fmap (read :: String -> Integer) . words <$> getLine
  putStr $ listToStrings $ solve nums


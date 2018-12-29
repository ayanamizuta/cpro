import Control.Applicative
import Text.Printf
--import Debug.Trace

solve :: Integer -> Bool -> [Integer]
solve n bl
  | n < 10 = [1,n]
  | (n `mod` 10 == 9 && bl) =[digit,su+n`mod`10]
  | otherwise = [digit2+1,su2+n`mod`10]
  where [digit,su] = solve (n `div` 10) bl
        [digit2,su2] = solve (n `div` 10) False

main = do
  n <- readLn
  let [digit,su] = solve n True
  printf "%d\n" $ (su + 9 * (digit-1))

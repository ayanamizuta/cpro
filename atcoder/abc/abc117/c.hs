import Control.Applicative
import Text.Printf
import Debug.Trace

qsort :: [Integer]->[Integer]
qsort [] = []
qsort (x:xs) = qsort left ++ [x] ++ qsort right
               where
                 left = filter (<=x) xs
                 right = filter (>x) xs

intervals_sub :: [Integer]->[Integer]
intervals_sub [x] = []
intervals_sub (x:xs) = ((head xs) - x):(intervals_sub xs)

intervals :: [Integer]->[Integer]
intervals l = let sl = qsort l in
                intervals_sub sl

solve :: Int->Int->[Integer]->Integer
solve n m x | n>=m = 0
            | otherwise = sum (take (m-n) $ qsort $ intervals x)

main :: IO ()
main = do
  [n,m] <- fmap (read :: String -> Int) . words <$> getLine
  x <- fmap (read :: String -> Integer) . words <$> getLine
  printf "%d\n" $ solve n m x

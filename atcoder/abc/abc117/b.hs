import Control.Applicative
import Text.Printf
import Debug.Trace

qsort :: [Int]->[Int]
qsort [] = []
qsort (x:xs) = qsort left ++ [x] ++ qsort right
               where
                 left = filter (<=x) xs
                 right = filter (>x) xs

solve :: [Int]->[Char]
solve l = let l_sorted = qsort l in
            if (last l_sorted) < (sum $ init l_sorted) then "Yes"
            else "No"

main :: IO ()
main = do
  n <- getLine
  l <- fmap (read :: String -> Int) . words <$> getLine
  putStrLn $ solve l

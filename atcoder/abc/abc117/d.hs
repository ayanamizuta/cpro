import Control.Applicative
import Text.Printf
import Debug.Trace

binsum_sub :: Integer->[Integer]->Integer
binsum_sub _ [] = 0
binsum_sub n (x:xs) = n*x + (binsum_sub (2*n) xs)

binsum :: [Integer]->Integer
binsum l = binsum_sub 1 l

bin :: Integer -> [Integer]
bin 0 = []
bin x = (x`mod`2):(bin (x`div`2))

suml :: [Integer]->[Integer]->[Integer]
suml x [] = x
suml [] y = y
suml (x:xs) (y:ys) = (x+y):(suml xs ys)

counter :: [Integer]->[Integer]
counter [] = bin 0
counter (x:xs) = let a = bin x in
                   suml a (counter xs)

calc :: Int->Integer->[Integer]->([Integer],[Integer])
calc _ k [] = ([],[])
calc n k (x:xs) = let (a,b) = calc n k xs in
                    (x:a,n-x:b)

solve_sub z o k d = 

solve n k a = let b = counter a
                  (zeros,ones) = calc n k b 0 in
                (binsum ((take digit (repeat 0))++(tails ((length zeros) - digit) zeros))) + (solve_sub zeros ones k digit)

main :: IO ()
main = do
  [n,k] <- fmap (read :: String -> Integer) . words <$> getLine
  a <- fmap (read :: String -> Int) . words <$> getLine
  printf "%d\n" $ solve n k a

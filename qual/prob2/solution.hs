import Control.Monad
import Data.List

split :: [a] -> ([a], [a])
split [] = ([], [])
split [x] = ([x], [])
split (x:y:l) = (x:odds, y:evens)
  where (odds, evens) = split l

merge :: [a] -> [a] -> [a]
merge [] [] = []
merge l [] = l
merge [] l = l
merge (a:l1) (b:l2) = a : b : merge l1 l2

solve :: [Int] -> Maybe Int
solve l =
  let (odds, evens) = split l
      sorted = merge (sort odds) (sort evens)
      pairs = zip3 [0..] sorted (tail sorted)
  in do
    (ndx, _, _) <- find (\(_, a, b) -> a > b) pairs
    return ndx

main = do
  t <- getLine >>= return . read
  forM_ [1..t] $ \t_ndx -> do
    _ <- getLine
    line <- getLine
    let list = map read $ words line
    let result = maybe "OK" show $ solve list
    putStrLn $ "Case #" ++ show (t_ndx) ++ ": " ++ result
    return ()

--
-- EPITECH PROJECT, 2021
-- B-FUN-300-LYN-3-1-funPoolDay2-jack.goodall
-- File description:
-- DoOp
--

import System.Environment ( getArgs )
import System.Exit ( ExitCode(ExitFailure), exitSuccess, exitWith )

------------Step 0-----------------

myElem :: (Eq a) => a -> [a] -> Bool
myElem i (a : aa) =
  (i == a) || myElem i aa
myElem _ _ = False

------------Step 1-----------------

safeDiv :: Int -> Int -> Maybe Int
safeDiv a b =
  if b == 0
    then Nothing
    else Just (a `div` b)

safeNth :: [a] -> Int -> Maybe a
safeNth arr i
  | i < 0 = Nothing
  | otherwise =
    if length arr <= i
      then Nothing
      else Just (arr !! i)

safeSucc :: Maybe Int -> Maybe Int
safeSucc i =
  i >>= (\x -> Just $ x + 1)

myLookup :: (Eq a) => a -> [(a, b)] -> Maybe b
myLookup i (a : aa) =
  if i == fst a
    then Just (snd a)
    else myLookup i aa
myLookup _ _ = Nothing

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo func (Just a) (Just b) = Just (func a b)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str =
  if all isDigit str
    then Just (read str)
    else Nothing
  where
    isDigit value = ('0' <= value && value <= '9') || value == '-'

------------Step 2-----------------

getLineLength :: IO Int
getLineLength =
  fmap length getLine

printAndGetLength :: String -> IO Int
printAndGetLength str =
  putStrLn str
    >> pure (length str)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox i =
  if i <= 0 then return ()
    else putStrLn
        ( ("+" ++ replicate (i * 2 - 2) '-' ++ "+\n")
            ++ take ((i * 2 + 1) * (i - 2))
              (cycle ("|" ++ replicate (i * 2 - 2) ' ' ++ "|\n"))
            ++ ("+" ++ replicate (i * 2 - 2) '-' ++ "+"))

concatLines :: Int -> IO String
concatLines i
  | i <= 0 = pure ""
  | otherwise = do
    line <- getLine
    rest <- concatLines (i - 1)
    pure (line ++ rest)

getInt :: IO (Maybe Int)
getInt =
  readInt <$> getLine

------------DOOP-----------------

doOp :: Maybe Int -> Maybe Char -> Maybe Int -> Maybe Int
doOp Nothing _ _ = Nothing
doOp _ _ Nothing = Nothing
doOp _ Nothing _ = Nothing
doOp (Just x) (Just '+') (Just y) = Just (x + y)
doOp (Just x) (Just '-') (Just y) = Just (x - y)
doOp (Just x) (Just '*') (Just y) = Just (x * y)
doOp (Just x) (Just '/') (Just y) = x `safeDiv` y
doOp (Just x) (Just '%') (Just y) =
  if y /= 0 then Just (x `mod` y) else Nothing
doOp _ _ _ = Nothing

printRes :: Maybe Int -> IO ()
printRes Nothing = exitWith (ExitFailure 84)
printRes (Just res) =
  print res >>
  exitSuccess

safeHead :: [a] -> Maybe a
safeHead (x : _) = Just x
safeHead _       = Nothing

main :: IO ()
main = do
  args <- getArgs
  if length args /= 3 then exitWith (ExitFailure 84)
    else (
        let x = readInt (head args)
            y = readInt (args !! 2)
            op = safeHead (args !! 1)
            res = doOp x op y
         in printRes res)

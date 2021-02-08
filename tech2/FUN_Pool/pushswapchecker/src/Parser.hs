--
-- EPITECH PROJECT, 2021
-- pushswap_checker
-- File description:
-- parser
--

module Parser where

----------Input Parser----------

inputIsValid :: [String] -> [String] -> Bool
inputIsValid []      _     = True
inputIsValid strings valid =
    (head strings `elem` valid) && inputIsValid (tail strings) valid

parseInput :: String -> Maybe [String]
parseInput str =
    let
        arr = words str
        valid = ["sa", "sb", "sc", "pa", "pb", "ra",
                "rb", "rr", "rra", "rrb", "rrr"]
    in
        if inputIsValid arr valid then Just arr
        else Nothing

getInput :: IO (Maybe [String])
getInput =
    parseInput <$> getLine

----------Arg Parser----------

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str =
  if (head str == '-' && all isDigit (tail str)) || all isDigit str
    then Just (read str)
    else Nothing
  where
    isDigit value = value `elem` ['0'..'9']

argIsValid :: Maybe Int -> Maybe [Int] -> Maybe [Int]
argIsValid  Nothing    _          = Nothing
argIsValid  _          Nothing    = Nothing
argIsValid (Just arg) (Just rest) = Just (arg : rest)

parseArgs :: [String] -> Maybe [Int]
parseArgs []      = Just []
parseArgs str_arr =
    let arg = readInt (head str_arr)
        rest = parseArgs (tail str_arr)
     in argIsValid arg rest

----------Sequence Cleaner----------

myClean :: [String] -> [String]
myClean ("sa":"sa":xs) = myClean xs
myClean ("sb":"sb":xs) = myClean xs
myClean ("sc":"sc":xs) = myClean xs
myClean ("pa":"pb":xs) = myClean xs
myClean ("pb":"pa":xs) = myClean xs
myClean ("rb":"rra":xs) = myClean xs
myClean ("rb":"rrb":xs) = myClean xs
myClean ("rra":"ra":xs) = myClean xs
myClean ("rrb":"rb":xs) = myClean xs
myClean (x:xs) = x : myClean xs
myClean _ = []

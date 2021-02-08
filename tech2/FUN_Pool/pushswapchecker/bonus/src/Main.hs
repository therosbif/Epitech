--
-- EPITECH PROJECT, 2021
-- B-FUN-300-LYN-3-1-pushswapchecker-jack.goodall
-- File description:
-- Main
--

module Main where

import PushSwap ( mySort )
import Parser ( parseArgs, getInput )
import MyGloss
import System.Environment ( getArgs )
import System.Exit
import Graphics.Gloss
import Sort ( doOps )

checkErrors :: Maybe [Int] -> IO ()
checkErrors Nothing = exitWith (ExitFailure 84)
checkErrors (Just to_sort)
    | length to_sort > 30 = exitWith (ExitFailure 84)
    | otherwise = pure ()

myClean :: [String] -> String
myClean ("sa":"sa":xs) = myClean xs
myClean ("sb":"sb":xs) = myClean xs
myClean ("pa":"pb":xs) = myClean xs
myClean ("pb":"pa":xs) = myClean xs
myClean (x:xs) = x ++ " " ++ myClean xs
myClean _ = ""



myCleanInit :: String -> String
myCleanInit str =
    let
        str_arr = words str
        cleaned = myClean str_arr
    in
        if cleaned == str
            then cleaned
            else myCleanInit cleaned

unMaybe :: Maybe a -> a
unMaybe (Just a) = a

indexValues :: [Int] -> Int -> [(Int, Int)]
indexValues (x : xs) index =
    (index, x) : indexValues xs (index + 1)
indexValues _ _ = []

friendlyValues :: [String] -> [Int] -> [(Int, Int)]
friendlyValues sequence to_sort =
    let sorted = fst (doOps sequence (to_sort, []))
    in indexValues sorted 0

main :: IO ()
main = do
    args <- getArgs
    let to_sort = parseArgs args
    input <- getLine
    checkErrors to_sort
    let sequence = if null input
        then myCleanInit (mySort (unMaybe to_sort, []))
        else input
    let friendly = friendlyValues (words (myCleanInit (mySort (unMaybe to_sort, [])))) (unMaybe to_sort)
    putStrLn sequence
    simulate windowDisplay white 5 (words sequence, (unMaybe to_sort, []), friendly) drawFunc updateFunc
    exitSuccess

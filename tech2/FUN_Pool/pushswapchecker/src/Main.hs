--
-- EPITECH PROJECT, 2021
-- pushswap_checker
-- File description:
-- main
--

module Main where

import Parser (getInput, parseArgs, myClean)
import Sort ( doOps, isSorted )
import System.Environment (getArgs)
import System.Exit ( ExitCode(ExitFailure), exitSuccess, exitWith )
import System.IO (hPutStrLn, stderr)

checkSort :: Maybe [String] -> Maybe [Int] -> IO ()
checkSort (Just sequence) (Just to_sort) =
  let sorted = doOps (myClean sequence) (to_sort, [])
  in if isSorted (fst sorted) && null (snd sorted)
      then putStrLn "OK" >> exitSuccess
      else putStr "KO: " >> print sorted >> exitSuccess

checkSort _ Nothing =
  hPutStrLn stderr "Invalid list of numbers" >> exitWith (ExitFailure 84)
checkSort Nothing _ =
  hPutStrLn stderr "Invalid sort sequence" >> exitWith (ExitFailure 84)

main :: IO ()
main = do
  args <- getArgs
  sequence <- getInput
  let parsed_args = parseArgs args
  checkSort sequence parsed_args

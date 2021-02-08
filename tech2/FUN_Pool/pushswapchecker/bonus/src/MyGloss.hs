{-# LANGUAGE ScopedTypeVariables #-}
module MyGloss where

import Graphics.Gloss
import Graphics.Gloss.Interface.Environment
import Graphics.Gloss.Data.ViewPort
import DoOp

type Model = ([String], ([Int], [Int]), [(Int, Int)])

windowDisplay :: Display
windowDisplay = InWindow "test-gloss" (1200, 600) (0, 0)

-- titles :: Picture
--   titles = pictures [text "list A", text "list B"]

bar :: Color -> Int -> (Int, Int) -> Picture
bar color pos (i, value) =
  let
    startx = -595 + (pos * 600)
    starty = (-300 + ((fromIntegral value :: Float) / 2))
  in
    Translate (fromIntegral startx + (fromIntegral i * 10 :: Float)) starty $
    Color color $ rectangleSolid 10 (fromIntegral value :: Float)

getIndex :: Int -> [(Int, Int)] -> Int
getIndex val ((i, v) : xs)
  | val == v = i
  | otherwise = getIndex val xs
getIndex _ [] = 0

drawGraph :: Color -> Int -> Int -> [Int] -> [(Int, Int)] -> Picture
drawGraph color _ _ [] _ =
  bar color 0 (0, 0)
drawGraph color pos from [l] friendly =
  bar color pos (from, 10 + getIndex l friendly * 50)
drawGraph color pos from (l : ls) friendly = pictures
  [bar color pos (from, 10 + getIndex l friendly * 50),
  drawGraph color pos (from + 1) ls friendly]

drawFunc :: Model -> Picture
drawFunc (sequence, (la, lb), friendly) = pictures
  [
  drawGraph red 0 0 la friendly,
  line[(0, -300), (0, 300)] ,
  drawGraph blue 1 0 lb friendly]

updateFunc :: ViewPort -> Float -> Model -> Model
updateFunc _ _ (s : ss, lists, friendly) = (ss, doOp s lists, friendly)
updateFunc _ _ ([], lists, friendly) = ([], lists, friendly)

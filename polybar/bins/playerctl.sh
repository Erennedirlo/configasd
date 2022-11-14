#!/bin/bash

postfix=""
prefix=""
artist="$(playerctl metadata xesam:artist 2>&1):"
title="$(playerctl metadata xesam:title 2>&1)"
get_status () {
  player_status="$(playerctl status 2>&1)"
  
  case $player_status in
    No*) echo "" ; exit 0
  esac
  
  if [ "$player_status" = "Paused" ]; then
    postfix="  "
  fi

}

is_spotify () {
  player_name="$(playerctl metadata mpris:trackid 2>&1)"
  case $player_name in
    /com/spotify/*) prefix="ﱘ "
  esac
}

get_artist () {
  artist_name="$(playerctl metadata xesam:artist 2>&1)"
  case $artist_name in
    "No player"*)
      artist=""
      ;;
    "")
      artist=""
      ;;
  esac
}

get_title () {
  title_name="$(playerctl metadata xesam:title 2>&1)"
  case $title_name in
    "No player"*)
      title=""
  esac
}
get_status
is_spotify
get_artist
get_title

towrite="${prefix} ${artist} ${title} ${postfix}"
if [ ${#towrite} -gt 65 ]; then
  towrite="$(echo ${towrite} | head -c 50) .... $(echo ${towrite} | tail -c 14)"
fi

echo $towrite

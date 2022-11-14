if status is-interactive
    # Commands to run in interactive sessions can go here
end

# Start X at login
#if status is-login
#	exec startx -- -keeptty
#end

fish_add_path /home/zekvaneren/.spicetify

alias feh='feh --scale-down --auto-zoom --image-bg black'

set -x GOOGLE_DEFAULT_CLIENT_SECRET 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
set -x GOOGLE_DEFAULT_CLIENT_ID 321597778990-r7c7c8ev3ksa4s4sghj5brgistsdp5it.apps.googleusercontent.com
set -x GOOGLE_API_KEY AIzaSyD_8LFGu8iBPkBkMSOoUfyLGEyr6guyVNk

#theme_gruvbox dark medium

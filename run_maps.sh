# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_maps.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 10:54:33 by llitovuo          #+#    #+#              #
#    Updated: 2024/03/26 12:02:18 by llitovuo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

R="\033[0;31m" # Red
G="\033[0;32m" # Green
Y="\033[0;33m" # yellow
B="\033[0;34m" # Blue
P="\033[0;35m" # Purple
C="\033[0;36m" # Cyan

RB="\033[1;31m" # Bold
GB="\033[1;32m"
YB="\033[1;33m"
BB="\033[1;34m"
PB="\033[1;35m"
CB="\033[1;36m"

RC="\033[0m" # Reset Color
FLL="**************"

#call srcs/check_path.c srcs/errors.c srcs/free_structs.c srcs/map_test.c srcs/parse_map.c srcs/validate_map.c libft/libft.a -o map_test
run_maptest()
{
	printf "${GB}Testing:${RC} ./so_long $1\n"
	#cat $1
	#printf "\n\n"
	printf "${BB}Output:\n${RC}"
	./so_long "$1"
	printf "${RC}${RB}Exit Code: ${RC}$?\n"
	#leaks --atExit -- ./map_test "$1"
	#sleep 1	
	printf "================================\n\n"
}

m1="maps/invalid/invalid_nocoll.ber"
m2="maps/invalid/invalid_noexit.ber"
m3="maps/invalid/invalid_noplayer.ber"
m4="maps/invalid/invalid_notrectangle.ber"
m5="maps/invalid/invalid_path.ber"
m6="maps/invalid/invalid_char.ber"
m7="maps/invalid/invalid_toobig.ber"
m8="maps/invalid/invalid_walls.ber"
m9="maps/invalid/newline_end.ber"
m10="maps/invalid/newline_middle.ber"
m11="maps/invalid/newline_start.ber"
m12="maps/invalid/newline_start.be"
m13="maps/invalid/newline_start.beri"
m14="maps/invalid/.ber"
m15="maps/invalid/empty_map.ber"

printf "\n${P}${FLL}****************${P}${FLL}${RC}\n"
printf "${P}${FLL}${RC}${RB}So_long MAP TEST${P}${FLL}${RC}\n"
printf "${P}${FLL}****************${P}${FLL}${RC}\n\n"

run_maptest
run_maptest ${m1}
run_maptest ${m2}
run_maptest ${m3}
run_maptest ${m4}
run_maptest ${m5}
run_maptest ${m6}
run_maptest ${m7}
run_maptest ${m8}
run_maptest ${m9}
run_maptest ${m10}
run_maptest ${m11}
run_maptest ${m12}
run_maptest ${m13}
run_maptest ${m14}
run_maptest ${m15}
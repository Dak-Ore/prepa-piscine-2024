# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_sh.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dak <dak@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:04:40 by dak               #+#    #+#              #
#    Updated: 2024/02/20 14:04:40 by dak              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

find . -name '*.sh' -type f -exec basename {} .sh \;
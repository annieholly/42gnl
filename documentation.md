# GNL LOGIC

## nl_op()
## This function processes what is in *saved

### Variables: 
#### linestr - to be copied into *line
#### newsaved - to be copied into *saved
#### nl - points to where the newline is within *saved

### IF (nothing exists in saved) 
#### - RETURN (0) - nothing left to process

### IF (newline is found inside *saved)
#### - linestr (MALLOC LS) = copy whats in saved until the newline into linestr variable
#### - newsaved (MALLOC NS) = copy whats after the newline into the newsaved variable
### ELSE 
#### - linestr (MALLOC LS) = copy everything in saved into linestr
#### - newsaved (MALLOC NS) = initialize to nothing to be freed

#### *line (MALLOC L) = copy linestr into *line
#### *saved (MALLOC S) = copy newsaved into *saved
#### FREE LS linestr
#### FREE NS newsaved

## get_next_line()

### Variables
#### ret - number of bytes read
#### buf - stores bytes read
#### *s - holds what's saved

### IF buf malloc fails (MALLOC B/initialize buf), fd is not valid, line doesn't exist
#### - RETURN (-1) 

### IF s is NULL - initialize s (MALLOC S)
#### - RETURN (-1) if malloc fails

### while (number of bytes read > 0) 
#### place null terminator at buf[ret]
#### s (MALLOC) = strjoin(s, buf)
### end while loop

### FREE buf malloc

### IF s[0] == '\0' - if nothing is left in s 
#### - RETURN (0) 
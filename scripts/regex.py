#27/04/2013 04:30
import re

def process_regex( regex, input, replacement = "" ):
    str_findall = ""
    str_split = ""
    str_sub = ""
    err_msg = ""
    try:
        cregex = re.compile( regex )

        #re.findall
        res_findall = cregex.findall( input )
        str_findall = str( res_findall )

        #re.split
        res_split = cregex.split( input )
        str_split = str( res_split )

        #re.sub
        res_sub = re.sub( regex, replacement, input )
        str_sub = str( res_sub )

        #re.finditer
        #groups = []
        #res_finditer = re.finditer( regex, input )
        #for match in res_finditer:
            #pos.append( match.groups() )
    except re.error, e:
        err_msg = str( e )


    ret = ( err_msg, str_findall, str_split, str_sub )
    return ret

#print process_regex( "(te)(st)", "test test west east best", ":" )

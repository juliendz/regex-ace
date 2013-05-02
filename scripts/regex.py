#27/04/2013 04:30
import re

def process_regex( regex, input, replacement , flag_ignorecase, flag_locale, flag_multiline, flag_dotall, flag_unicode, flag_verbose, flag_debug ):
    err_msg = ""
    str_findall = ""
    str_split = ""
    str_sub = ""

    #re flags
    flags = 0
    flags |= re.IGNORECASE if ( flag_ignorecase == 1 ) else 0
    flags |= re.LOCALE if ( flag_locale == 1 ) else 0
    flags |= re.MULTILINE if ( flag_multiline == 1 ) else 0
    flags |= re.DOTALL if ( flag_dotall == 1 ) else 0
    flags |= re.UNICODE if ( flag_unicode == 1 ) else 0
    flags |= re.VERBOSE if ( flag_verbose == 1 ) else 0
    flags |= re.DEBUG if ( flag_debug == 1 ) else 0

    try:
        cregex = re.compile( regex, flags )

        #re.findall
        res_findall = cregex.findall( input )
        str_findall = str( res_findall )

        #re.split
        res_split = cregex.split( input )
        str_split = str( res_split )

        #re.sub
        res_sub = re.sub( regex, replacement, input, 0, flags )
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

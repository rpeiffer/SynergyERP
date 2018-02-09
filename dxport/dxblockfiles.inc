!dxblockfiles.inc files def include!
!
Def Struct BlockConfig   !dfsystem.txt parameters
 Member filetype$[2]
 Member drvr$[60]
 Member filedir$[80]
 Member filehdr$[60]
 Member filecol$[60]
 Member fileinp$[60]
 Member fileinplst$[60]
 Member filebut$[60]
 Member printerchannel$[3]
 Member sortchannel$[3]
 Member dateformat$[80]
 Member guititle$[80]
 Member guifooter$[80]
 Member 1%,guiminrows
 Member guireturn$[80]
End Def
!
Def Struct blockhdr
 Member ID$[8]          :Item "ID"
 Member desc$[60]       :Item "Description"
 Member filename$[20]   :Item "Filename"
 Member title$[60]      :Item "Title"
 Member subtitle$[60]   :Item "Subtitle"
 Member include1$[60]   :Item "include1"
 Member include2$[60]   :Item "include2"
 Member custom1$[8]     :Item "Custom1"
 Member custom2$[8]     :Item "Custom2"
 Member custom3$[8]     :Item "Custom3"
 Member optionid$[8]    :Item "OptionID"        !reserved
 Member appid$[20]      :Item "AppID"   !reserved
 Member parentid$[8]    :Item "ParentID"        !reserved
 Member rowlink$[120]   :Item "Rowlink"
 Member evenodd$[1]     :Item "Evenodd"
 Member programname$[20]:Item "Program" !override programname to chain to
 Member addeddate$[16]  :Item "addeddate"
 Member addedby$[8]     :Item "addedby"
 Member updateddate$[16]:Item "updateddate"
 Member updatedby$[8]   :Item "updatedby"
 Member conditions$[100]:Item "conditions"
End Def
!
Def Struct blockcol
 Member ID$[8]          :Item "ID"
 Member 1%,seq          :Item "Seq"
 Member label$[40]      :Item "Label"
 Member active$[1]      :Item "Active"
 Member link$[120]      :Item "Link"
 Member style$[120]     :Item "Style"
 Member width$[10]      :Item "Width"
 Member varname$[40]    :Item "Varname"
 Member mask$[20]       :Item "Mask"        !numeric only, display mask
 Member 1%,inpseq       :Item "Inpseq"      !if <>0 use blockinp definition for defaults
 Member dbfieldname$[30]:Item "Dbfieldname"
 Member 2%,dbposition   :Item "Dbposition"
 Member 2%,dbprecision  :Item "Dbprecision"
 Member dbtype$[20]     :Item "Dbtype"
End Def
!
Def Struct blockinp
 Member ID$[8]          :Item "ID"
 Member 1%,seq          :Item "Seq"
 Member label$[40]      :Item "Label"
 Member active$[1]      :Item "Active"
 Member varname$[40]    :Item "Varname"
 Member 1%,row          :Item "Row"                     !Reserved future
 Member 1%,column       :Item "Column"                  !Reserved future
 Member type$[20]       :Item "Type"
 Member required$[1]    :Item "Required"
 Member default$[120]   :Item "Default"   !if checkbox, it will be blank or 'checked'
 Member disabled$[1]    :Item "Disabled"
 Member notab$[1]       :Item "Notab"
 Member focus$[1]       :Item "Focus"
 Member lookuplink$[80] :Item "Lookuplink"
 Member helppage$[80]   :Item "Helppage"                !actually short help text
 Member onfocus$[120]   :Item "Onfocus"
 Member onchange$[120]  :Item "Onchange"
 Member userdef1$[60]   :Item "Userdef1"
 Member userdef2$[60]   :Item "Userdef2"
 Member userdef3$[60]   :Item "Userdef3"
 Member userdef4$[60]   :Item "Userdef4"
 Member userdef5$[60]   :Item "Userdef5"
 Member dbfieldname$[30]:Item "Dbfieldname"
 Member 2%,dbposition   :Item "Dbposition"
 Member 2%,dbprecision  :Item "Dbprecision"
 Member dbtype$[20]     :Item "Dbtype"
 Member 4%,minlength    :Item "Minlength"  !text only   if numeric minvalue
 Member 4%,maxlength    :Item "Maxlength"  !text only   if numeric maxvalue
 Member mask$[20]       :Item "Mask"       !numeric only, edit mask
 Member checkvalue$[20] :Item "Checkvalue" !value to pass if checkbox checked 
 Member listfilename$[20]:Item "Listfilename" !list and list:text filename to generate list from
 Member 1%,maxselected  :Item "Maxselected" !list only, max that can be selected
 Member 1%,maxlisted    :Item "Maxlisted"  !list:text, max to show in list
 Member masterdesc$[60] :Item "Masterdesc" !MASTER blockids only, description of the field
 Member 1%,masterseq	:Item "Masterseq"  !MASTER seq # to refer back to for default properties
 Member conditions$[100]:Item "conditions"
End Def
!
Def Struct blockinplst
 Member ID$[8]          :Item "ID"
 Member 1%,seq          :Item "Seq"     !seq of input field
 Member 1%,listseq      :Item "Listseq"
 Member label$[40]      :Item "Label"
 Member active$[1]      :Item "Active"
 Member value$[120]     :Item "Value"
End Def
!
Def Struct blockbut
 Member ID$[8]          :Item "ID"
 Member 1%,seq          :Item "Seq"
 Member label$[40]      :Item "Label"
 Member active$[1]      :Item "Active"
 Member link$[120]      :Item "Link"
End Def
!
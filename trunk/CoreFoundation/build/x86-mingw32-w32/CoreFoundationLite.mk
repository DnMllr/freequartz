##
## Auto Generated makefile, please do not edit
##
ProjectName:=CoreFoundationLite

## Debug
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "C:\lal\openquartz\openquartz_20091227\openquartz\src\CoreFoundationLite\build\x86-mingw32-w32"
ProjectPath            := "C:\lal\openquartz\openquartz_20091227\openquartz\src\CoreFoundationLite\build\x86-mingw32-w32"
CurrentFileName        :=
CurrentFulePath        :=
CurrentFileFullPath    :=
User                   :=Vincent
Date                   :=12/28/09
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
OutputFile             :=$(IntermediateDirectory)/CoreFoundation.dll
Preprocessors          :=$(PreprocessorSwitch)CFLITELIB_EXPORTS $(PreprocessorSwitch)DEPLOYMENT_TARGET_WINDOWS $(PreprocessorSwitch)WIN32_LEAN_AND_MEAN $(PreprocessorSwitch)__STDC_LIMIT_MACROS $(PreprocessorSwitch)CF_BUILDING_CF $(PreprocessorSwitch)_WIN32_WINNT=0x0500 $(PreprocessorSwitch)WINVER=0x0500 $(PreprocessorSwitch)_UNICODE $(PreprocessorSwitch)UNICODE 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=
CmpOptions             := -g -fno-exceptions $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." "$(IncludeSwitch)../../dist/include" "$(IncludeSwitch)../../include" "$(IncludeSwitch)../../icu" 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)netapi32 $(LibrarySwitch)ole32 $(LibrarySwitch)ws2_32 $(LibrarySwitch)kernel32 $(LibrarySwitch)icuuc $(LibrarySwitch)icuin $(LibrarySwitch)rpcrt4 $(LibrarySwitch)msvcrt 
LibPath                := "$(LibraryPathSwitch)." "$(LibraryPathSwitch)../../icu/lib/x86-mingw32-w32" 


Objects=$(IntermediateDirectory)/CFApplicationPreferences$(ObjectSuffix) $(IntermediateDirectory)/CFArray$(ObjectSuffix) $(IntermediateDirectory)/CFBag$(ObjectSuffix) $(IntermediateDirectory)/CFBase$(ObjectSuffix) $(IntermediateDirectory)/CFBinaryHeap$(ObjectSuffix) $(IntermediateDirectory)/CFBinaryPList$(ObjectSuffix) $(IntermediateDirectory)/CFBitVector$(ObjectSuffix) $(IntermediateDirectory)/CFBuiltinConverters$(ObjectSuffix) $(IntermediateDirectory)/CFBundle$(ObjectSuffix) $(IntermediateDirectory)/CFBundle_Resources$(ObjectSuffix) \
	$(IntermediateDirectory)/CFCalendar$(ObjectSuffix) $(IntermediateDirectory)/CFCharacterSet$(ObjectSuffix) $(IntermediateDirectory)/CFConcreteStreams$(ObjectSuffix) $(IntermediateDirectory)/CFData$(ObjectSuffix) $(IntermediateDirectory)/CFDate$(ObjectSuffix) $(IntermediateDirectory)/CFDateFormatter$(ObjectSuffix) $(IntermediateDirectory)/CFDictionary$(ObjectSuffix) $(IntermediateDirectory)/CFError$(ObjectSuffix) $(IntermediateDirectory)/CFFileDescriptor$(ObjectSuffix) $(IntermediateDirectory)/CFFileUtilities$(ObjectSuffix) \
	$(IntermediateDirectory)/CFLocale$(ObjectSuffix) $(IntermediateDirectory)/CFLocaleIdentifier$(ObjectSuffix) $(IntermediateDirectory)/CFMachPort$(ObjectSuffix) $(IntermediateDirectory)/CFMessagePort$(ObjectSuffix) $(IntermediateDirectory)/CFNotificationCenter$(ObjectSuffix) $(IntermediateDirectory)/CFNumber$(ObjectSuffix) $(IntermediateDirectory)/CFNumberFormatter$(ObjectSuffix) $(IntermediateDirectory)/CFPlatform$(ObjectSuffix) $(IntermediateDirectory)/CFPlugIn$(ObjectSuffix) $(IntermediateDirectory)/CFPlugIn_Factory$(ObjectSuffix) \
	$(IntermediateDirectory)/CFPlugIn_Instance$(ObjectSuffix) $(IntermediateDirectory)/CFPlugIn_PlugIn$(ObjectSuffix) $(IntermediateDirectory)/CFPreferences$(ObjectSuffix) $(IntermediateDirectory)/CFPropertyList$(ObjectSuffix) $(IntermediateDirectory)/CFRunLoop$(ObjectSuffix) $(IntermediateDirectory)/CFRuntime$(ObjectSuffix) $(IntermediateDirectory)/CFSet$(ObjectSuffix) $(IntermediateDirectory)/CFSocket$(ObjectSuffix) $(IntermediateDirectory)/CFSocketStream$(ObjectSuffix) $(IntermediateDirectory)/CFSortFunctions$(ObjectSuffix) \
	$(IntermediateDirectory)/CFStorage$(ObjectSuffix) $(IntermediateDirectory)/CFStream$(ObjectSuffix) $(IntermediateDirectory)/CFString$(ObjectSuffix) $(IntermediateDirectory)/CFStringEncodingConverter$(ObjectSuffix) $(IntermediateDirectory)/CFStringEncodings$(ObjectSuffix) $(IntermediateDirectory)/CFStringScanner$(ObjectSuffix) $(IntermediateDirectory)/CFStringUtilities$(ObjectSuffix) $(IntermediateDirectory)/CFSystemDirectories$(ObjectSuffix) $(IntermediateDirectory)/CFTimeZone$(ObjectSuffix) $(IntermediateDirectory)/CFTree$(ObjectSuffix) \
	$(IntermediateDirectory)/CFUniChar$(ObjectSuffix) $(IntermediateDirectory)/CFUnicodeDecomposition$(ObjectSuffix) $(IntermediateDirectory)/CFUnicodePrecomposition$(ObjectSuffix) $(IntermediateDirectory)/CFURL$(ObjectSuffix) $(IntermediateDirectory)/CFURLAccess$(ObjectSuffix) $(IntermediateDirectory)/CFUserNotification$(ObjectSuffix) $(IntermediateDirectory)/CFUtilities$(ObjectSuffix) $(IntermediateDirectory)/CFUUID$(ObjectSuffix) $(IntermediateDirectory)/CFVersion$(ObjectSuffix) $(IntermediateDirectory)/CFWindowsMessageQueue$(ObjectSuffix) \
	$(IntermediateDirectory)/CFXMLInputStream$(ObjectSuffix) $(IntermediateDirectory)/CFXMLNode$(ObjectSuffix) $(IntermediateDirectory)/CFXMLParser$(ObjectSuffix) $(IntermediateDirectory)/CFXMLPreferencesDomain$(ObjectSuffix) $(IntermediateDirectory)/CFXMLTree$(ObjectSuffix) $(IntermediateDirectory)/dirent$(ObjectSuffix) $(IntermediateDirectory)/flsl$(ObjectSuffix) $(IntermediateDirectory)/gettimeofday$(ObjectSuffix) $(IntermediateDirectory)/strlcat$(ObjectSuffix) $(IntermediateDirectory)/strlcpy$(ObjectSuffix) \
	

##
## Main Build Tragets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@makedir $(@D)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@makedir "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/CFApplicationPreferences$(ObjectSuffix): ../../CFApplicationPreferences.c $(IntermediateDirectory)/CFApplicationPreferences$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFApplicationPreferences.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFApplicationPreferences$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFApplicationPreferences$(DependSuffix): ../../CFApplicationPreferences.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFApplicationPreferences$(ObjectSuffix) -MF$(IntermediateDirectory)/CFApplicationPreferences$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFApplicationPreferences.c"

$(IntermediateDirectory)/CFArray$(ObjectSuffix): ../../CFArray.c $(IntermediateDirectory)/CFArray$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFArray.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFArray$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFArray$(DependSuffix): ../../CFArray.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFArray$(ObjectSuffix) -MF$(IntermediateDirectory)/CFArray$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFArray.c"

$(IntermediateDirectory)/CFBag$(ObjectSuffix): ../../CFBag.c $(IntermediateDirectory)/CFBag$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBag.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBag$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBag$(DependSuffix): ../../CFBag.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBag$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBag$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBag.c"

$(IntermediateDirectory)/CFBase$(ObjectSuffix): ../../CFBase.c $(IntermediateDirectory)/CFBase$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBase.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBase$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBase$(DependSuffix): ../../CFBase.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBase$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBase$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBase.c"

$(IntermediateDirectory)/CFBinaryHeap$(ObjectSuffix): ../../CFBinaryHeap.c $(IntermediateDirectory)/CFBinaryHeap$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBinaryHeap.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBinaryHeap$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBinaryHeap$(DependSuffix): ../../CFBinaryHeap.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBinaryHeap$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBinaryHeap$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBinaryHeap.c"

$(IntermediateDirectory)/CFBinaryPList$(ObjectSuffix): ../../CFBinaryPList.c $(IntermediateDirectory)/CFBinaryPList$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBinaryPList.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBinaryPList$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBinaryPList$(DependSuffix): ../../CFBinaryPList.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBinaryPList$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBinaryPList$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBinaryPList.c"

$(IntermediateDirectory)/CFBitVector$(ObjectSuffix): ../../CFBitVector.c $(IntermediateDirectory)/CFBitVector$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBitVector.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBitVector$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBitVector$(DependSuffix): ../../CFBitVector.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBitVector$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBitVector$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBitVector.c"

$(IntermediateDirectory)/CFBuiltinConverters$(ObjectSuffix): ../../CFBuiltinConverters.c $(IntermediateDirectory)/CFBuiltinConverters$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBuiltinConverters.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBuiltinConverters$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBuiltinConverters$(DependSuffix): ../../CFBuiltinConverters.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBuiltinConverters$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBuiltinConverters$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBuiltinConverters.c"

$(IntermediateDirectory)/CFBundle$(ObjectSuffix): ../../CFBundle.c $(IntermediateDirectory)/CFBundle$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBundle.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBundle$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBundle$(DependSuffix): ../../CFBundle.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBundle$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBundle$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBundle.c"

$(IntermediateDirectory)/CFBundle_Resources$(ObjectSuffix): ../../CFBundle_Resources.c $(IntermediateDirectory)/CFBundle_Resources$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBundle_Resources.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFBundle_Resources$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFBundle_Resources$(DependSuffix): ../../CFBundle_Resources.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFBundle_Resources$(ObjectSuffix) -MF$(IntermediateDirectory)/CFBundle_Resources$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFBundle_Resources.c"

$(IntermediateDirectory)/CFCalendar$(ObjectSuffix): ../../CFCalendar.c $(IntermediateDirectory)/CFCalendar$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFCalendar.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFCalendar$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFCalendar$(DependSuffix): ../../CFCalendar.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFCalendar$(ObjectSuffix) -MF$(IntermediateDirectory)/CFCalendar$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFCalendar.c"

$(IntermediateDirectory)/CFCharacterSet$(ObjectSuffix): ../../CFCharacterSet.c $(IntermediateDirectory)/CFCharacterSet$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFCharacterSet.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFCharacterSet$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFCharacterSet$(DependSuffix): ../../CFCharacterSet.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFCharacterSet$(ObjectSuffix) -MF$(IntermediateDirectory)/CFCharacterSet$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFCharacterSet.c"

$(IntermediateDirectory)/CFConcreteStreams$(ObjectSuffix): ../../CFConcreteStreams.c $(IntermediateDirectory)/CFConcreteStreams$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFConcreteStreams.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFConcreteStreams$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFConcreteStreams$(DependSuffix): ../../CFConcreteStreams.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFConcreteStreams$(ObjectSuffix) -MF$(IntermediateDirectory)/CFConcreteStreams$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFConcreteStreams.c"

$(IntermediateDirectory)/CFData$(ObjectSuffix): ../../CFData.c $(IntermediateDirectory)/CFData$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFData.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFData$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFData$(DependSuffix): ../../CFData.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFData$(ObjectSuffix) -MF$(IntermediateDirectory)/CFData$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFData.c"

$(IntermediateDirectory)/CFDate$(ObjectSuffix): ../../CFDate.c $(IntermediateDirectory)/CFDate$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFDate.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFDate$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFDate$(DependSuffix): ../../CFDate.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFDate$(ObjectSuffix) -MF$(IntermediateDirectory)/CFDate$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFDate.c"

$(IntermediateDirectory)/CFDateFormatter$(ObjectSuffix): ../../CFDateFormatter.c $(IntermediateDirectory)/CFDateFormatter$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFDateFormatter.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFDateFormatter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFDateFormatter$(DependSuffix): ../../CFDateFormatter.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFDateFormatter$(ObjectSuffix) -MF$(IntermediateDirectory)/CFDateFormatter$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFDateFormatter.c"

$(IntermediateDirectory)/CFDictionary$(ObjectSuffix): ../../CFDictionary.c $(IntermediateDirectory)/CFDictionary$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFDictionary.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFDictionary$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFDictionary$(DependSuffix): ../../CFDictionary.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFDictionary$(ObjectSuffix) -MF$(IntermediateDirectory)/CFDictionary$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFDictionary.c"

$(IntermediateDirectory)/CFError$(ObjectSuffix): ../../CFError.c $(IntermediateDirectory)/CFError$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFError.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFError$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFError$(DependSuffix): ../../CFError.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFError$(ObjectSuffix) -MF$(IntermediateDirectory)/CFError$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFError.c"

$(IntermediateDirectory)/CFFileDescriptor$(ObjectSuffix): ../../CFFileDescriptor.c $(IntermediateDirectory)/CFFileDescriptor$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFFileDescriptor.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFFileDescriptor$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFFileDescriptor$(DependSuffix): ../../CFFileDescriptor.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFFileDescriptor$(ObjectSuffix) -MF$(IntermediateDirectory)/CFFileDescriptor$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFFileDescriptor.c"

$(IntermediateDirectory)/CFFileUtilities$(ObjectSuffix): ../../CFFileUtilities.c $(IntermediateDirectory)/CFFileUtilities$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFFileUtilities.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFFileUtilities$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFFileUtilities$(DependSuffix): ../../CFFileUtilities.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFFileUtilities$(ObjectSuffix) -MF$(IntermediateDirectory)/CFFileUtilities$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFFileUtilities.c"

$(IntermediateDirectory)/CFLocale$(ObjectSuffix): ../../CFLocale.c $(IntermediateDirectory)/CFLocale$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFLocale.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFLocale$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFLocale$(DependSuffix): ../../CFLocale.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFLocale$(ObjectSuffix) -MF$(IntermediateDirectory)/CFLocale$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFLocale.c"

$(IntermediateDirectory)/CFLocaleIdentifier$(ObjectSuffix): ../../CFLocaleIdentifier.c $(IntermediateDirectory)/CFLocaleIdentifier$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFLocaleIdentifier.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFLocaleIdentifier$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFLocaleIdentifier$(DependSuffix): ../../CFLocaleIdentifier.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFLocaleIdentifier$(ObjectSuffix) -MF$(IntermediateDirectory)/CFLocaleIdentifier$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFLocaleIdentifier.c"

$(IntermediateDirectory)/CFMachPort$(ObjectSuffix): ../../CFMachPort.c $(IntermediateDirectory)/CFMachPort$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFMachPort.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFMachPort$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFMachPort$(DependSuffix): ../../CFMachPort.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFMachPort$(ObjectSuffix) -MF$(IntermediateDirectory)/CFMachPort$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFMachPort.c"

$(IntermediateDirectory)/CFMessagePort$(ObjectSuffix): ../../CFMessagePort.c $(IntermediateDirectory)/CFMessagePort$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFMessagePort.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFMessagePort$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFMessagePort$(DependSuffix): ../../CFMessagePort.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFMessagePort$(ObjectSuffix) -MF$(IntermediateDirectory)/CFMessagePort$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFMessagePort.c"

$(IntermediateDirectory)/CFNotificationCenter$(ObjectSuffix): ../../CFNotificationCenter.c $(IntermediateDirectory)/CFNotificationCenter$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFNotificationCenter.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFNotificationCenter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFNotificationCenter$(DependSuffix): ../../CFNotificationCenter.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFNotificationCenter$(ObjectSuffix) -MF$(IntermediateDirectory)/CFNotificationCenter$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFNotificationCenter.c"

$(IntermediateDirectory)/CFNumber$(ObjectSuffix): ../../CFNumber.c $(IntermediateDirectory)/CFNumber$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFNumber.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFNumber$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFNumber$(DependSuffix): ../../CFNumber.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFNumber$(ObjectSuffix) -MF$(IntermediateDirectory)/CFNumber$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFNumber.c"

$(IntermediateDirectory)/CFNumberFormatter$(ObjectSuffix): ../../CFNumberFormatter.c $(IntermediateDirectory)/CFNumberFormatter$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFNumberFormatter.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFNumberFormatter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFNumberFormatter$(DependSuffix): ../../CFNumberFormatter.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFNumberFormatter$(ObjectSuffix) -MF$(IntermediateDirectory)/CFNumberFormatter$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFNumberFormatter.c"

$(IntermediateDirectory)/CFPlatform$(ObjectSuffix): ../../CFPlatform.c $(IntermediateDirectory)/CFPlatform$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlatform.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFPlatform$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFPlatform$(DependSuffix): ../../CFPlatform.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFPlatform$(ObjectSuffix) -MF$(IntermediateDirectory)/CFPlatform$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlatform.c"

$(IntermediateDirectory)/CFPlugIn$(ObjectSuffix): ../../CFPlugIn.c $(IntermediateDirectory)/CFPlugIn$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFPlugIn$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFPlugIn$(DependSuffix): ../../CFPlugIn.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFPlugIn$(ObjectSuffix) -MF$(IntermediateDirectory)/CFPlugIn$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn.c"

$(IntermediateDirectory)/CFPlugIn_Factory$(ObjectSuffix): ../../CFPlugIn_Factory.c $(IntermediateDirectory)/CFPlugIn_Factory$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn_Factory.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFPlugIn_Factory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFPlugIn_Factory$(DependSuffix): ../../CFPlugIn_Factory.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFPlugIn_Factory$(ObjectSuffix) -MF$(IntermediateDirectory)/CFPlugIn_Factory$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn_Factory.c"

$(IntermediateDirectory)/CFPlugIn_Instance$(ObjectSuffix): ../../CFPlugIn_Instance.c $(IntermediateDirectory)/CFPlugIn_Instance$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn_Instance.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFPlugIn_Instance$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFPlugIn_Instance$(DependSuffix): ../../CFPlugIn_Instance.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFPlugIn_Instance$(ObjectSuffix) -MF$(IntermediateDirectory)/CFPlugIn_Instance$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn_Instance.c"

$(IntermediateDirectory)/CFPlugIn_PlugIn$(ObjectSuffix): ../../CFPlugIn_PlugIn.c $(IntermediateDirectory)/CFPlugIn_PlugIn$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn_PlugIn.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFPlugIn_PlugIn$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFPlugIn_PlugIn$(DependSuffix): ../../CFPlugIn_PlugIn.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFPlugIn_PlugIn$(ObjectSuffix) -MF$(IntermediateDirectory)/CFPlugIn_PlugIn$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPlugIn_PlugIn.c"

$(IntermediateDirectory)/CFPreferences$(ObjectSuffix): ../../CFPreferences.c $(IntermediateDirectory)/CFPreferences$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPreferences.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFPreferences$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFPreferences$(DependSuffix): ../../CFPreferences.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFPreferences$(ObjectSuffix) -MF$(IntermediateDirectory)/CFPreferences$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPreferences.c"

$(IntermediateDirectory)/CFPropertyList$(ObjectSuffix): ../../CFPropertyList.c $(IntermediateDirectory)/CFPropertyList$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPropertyList.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFPropertyList$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFPropertyList$(DependSuffix): ../../CFPropertyList.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFPropertyList$(ObjectSuffix) -MF$(IntermediateDirectory)/CFPropertyList$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFPropertyList.c"

$(IntermediateDirectory)/CFRunLoop$(ObjectSuffix): ../../CFRunLoop.c $(IntermediateDirectory)/CFRunLoop$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFRunLoop.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFRunLoop$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFRunLoop$(DependSuffix): ../../CFRunLoop.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFRunLoop$(ObjectSuffix) -MF$(IntermediateDirectory)/CFRunLoop$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFRunLoop.c"

$(IntermediateDirectory)/CFRuntime$(ObjectSuffix): ../../CFRuntime.c $(IntermediateDirectory)/CFRuntime$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFRuntime.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFRuntime$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFRuntime$(DependSuffix): ../../CFRuntime.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFRuntime$(ObjectSuffix) -MF$(IntermediateDirectory)/CFRuntime$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFRuntime.c"

$(IntermediateDirectory)/CFSet$(ObjectSuffix): ../../CFSet.c $(IntermediateDirectory)/CFSet$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSet.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFSet$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFSet$(DependSuffix): ../../CFSet.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFSet$(ObjectSuffix) -MF$(IntermediateDirectory)/CFSet$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSet.c"

$(IntermediateDirectory)/CFSocket$(ObjectSuffix): ../../CFSocket.c $(IntermediateDirectory)/CFSocket$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSocket.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFSocket$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFSocket$(DependSuffix): ../../CFSocket.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFSocket$(ObjectSuffix) -MF$(IntermediateDirectory)/CFSocket$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSocket.c"

$(IntermediateDirectory)/CFSocketStream$(ObjectSuffix): ../../CFSocketStream.c $(IntermediateDirectory)/CFSocketStream$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSocketStream.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFSocketStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFSocketStream$(DependSuffix): ../../CFSocketStream.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFSocketStream$(ObjectSuffix) -MF$(IntermediateDirectory)/CFSocketStream$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSocketStream.c"

$(IntermediateDirectory)/CFSortFunctions$(ObjectSuffix): ../../CFSortFunctions.c $(IntermediateDirectory)/CFSortFunctions$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSortFunctions.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFSortFunctions$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFSortFunctions$(DependSuffix): ../../CFSortFunctions.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFSortFunctions$(ObjectSuffix) -MF$(IntermediateDirectory)/CFSortFunctions$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSortFunctions.c"

$(IntermediateDirectory)/CFStorage$(ObjectSuffix): ../../CFStorage.c $(IntermediateDirectory)/CFStorage$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStorage.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFStorage$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFStorage$(DependSuffix): ../../CFStorage.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFStorage$(ObjectSuffix) -MF$(IntermediateDirectory)/CFStorage$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStorage.c"

$(IntermediateDirectory)/CFStream$(ObjectSuffix): ../../CFStream.c $(IntermediateDirectory)/CFStream$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStream.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFStream$(DependSuffix): ../../CFStream.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFStream$(ObjectSuffix) -MF$(IntermediateDirectory)/CFStream$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStream.c"

$(IntermediateDirectory)/CFString$(ObjectSuffix): ../../CFString.c $(IntermediateDirectory)/CFString$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFString.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFString$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFString$(DependSuffix): ../../CFString.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFString$(ObjectSuffix) -MF$(IntermediateDirectory)/CFString$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFString.c"

$(IntermediateDirectory)/CFStringEncodingConverter$(ObjectSuffix): ../../CFStringEncodingConverter.c $(IntermediateDirectory)/CFStringEncodingConverter$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringEncodingConverter.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFStringEncodingConverter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFStringEncodingConverter$(DependSuffix): ../../CFStringEncodingConverter.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFStringEncodingConverter$(ObjectSuffix) -MF$(IntermediateDirectory)/CFStringEncodingConverter$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringEncodingConverter.c"

$(IntermediateDirectory)/CFStringEncodings$(ObjectSuffix): ../../CFStringEncodings.c $(IntermediateDirectory)/CFStringEncodings$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringEncodings.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFStringEncodings$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFStringEncodings$(DependSuffix): ../../CFStringEncodings.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFStringEncodings$(ObjectSuffix) -MF$(IntermediateDirectory)/CFStringEncodings$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringEncodings.c"

$(IntermediateDirectory)/CFStringScanner$(ObjectSuffix): ../../CFStringScanner.c $(IntermediateDirectory)/CFStringScanner$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringScanner.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFStringScanner$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFStringScanner$(DependSuffix): ../../CFStringScanner.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFStringScanner$(ObjectSuffix) -MF$(IntermediateDirectory)/CFStringScanner$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringScanner.c"

$(IntermediateDirectory)/CFStringUtilities$(ObjectSuffix): ../../CFStringUtilities.c $(IntermediateDirectory)/CFStringUtilities$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringUtilities.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFStringUtilities$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFStringUtilities$(DependSuffix): ../../CFStringUtilities.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFStringUtilities$(ObjectSuffix) -MF$(IntermediateDirectory)/CFStringUtilities$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFStringUtilities.c"

$(IntermediateDirectory)/CFSystemDirectories$(ObjectSuffix): ../../CFSystemDirectories.c $(IntermediateDirectory)/CFSystemDirectories$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSystemDirectories.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFSystemDirectories$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFSystemDirectories$(DependSuffix): ../../CFSystemDirectories.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFSystemDirectories$(ObjectSuffix) -MF$(IntermediateDirectory)/CFSystemDirectories$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFSystemDirectories.c"

$(IntermediateDirectory)/CFTimeZone$(ObjectSuffix): ../../CFTimeZone.c $(IntermediateDirectory)/CFTimeZone$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFTimeZone.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFTimeZone$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFTimeZone$(DependSuffix): ../../CFTimeZone.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFTimeZone$(ObjectSuffix) -MF$(IntermediateDirectory)/CFTimeZone$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFTimeZone.c"

$(IntermediateDirectory)/CFTree$(ObjectSuffix): ../../CFTree.c $(IntermediateDirectory)/CFTree$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFTree.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFTree$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFTree$(DependSuffix): ../../CFTree.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFTree$(ObjectSuffix) -MF$(IntermediateDirectory)/CFTree$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFTree.c"

$(IntermediateDirectory)/CFUniChar$(ObjectSuffix): ../../CFUniChar.c $(IntermediateDirectory)/CFUniChar$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUniChar.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFUniChar$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFUniChar$(DependSuffix): ../../CFUniChar.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFUniChar$(ObjectSuffix) -MF$(IntermediateDirectory)/CFUniChar$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUniChar.c"

$(IntermediateDirectory)/CFUnicodeDecomposition$(ObjectSuffix): ../../CFUnicodeDecomposition.c $(IntermediateDirectory)/CFUnicodeDecomposition$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUnicodeDecomposition.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFUnicodeDecomposition$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFUnicodeDecomposition$(DependSuffix): ../../CFUnicodeDecomposition.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFUnicodeDecomposition$(ObjectSuffix) -MF$(IntermediateDirectory)/CFUnicodeDecomposition$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUnicodeDecomposition.c"

$(IntermediateDirectory)/CFUnicodePrecomposition$(ObjectSuffix): ../../CFUnicodePrecomposition.c $(IntermediateDirectory)/CFUnicodePrecomposition$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUnicodePrecomposition.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFUnicodePrecomposition$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFUnicodePrecomposition$(DependSuffix): ../../CFUnicodePrecomposition.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFUnicodePrecomposition$(ObjectSuffix) -MF$(IntermediateDirectory)/CFUnicodePrecomposition$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUnicodePrecomposition.c"

$(IntermediateDirectory)/CFURL$(ObjectSuffix): ../../CFURL.c $(IntermediateDirectory)/CFURL$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFURL.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFURL$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFURL$(DependSuffix): ../../CFURL.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFURL$(ObjectSuffix) -MF$(IntermediateDirectory)/CFURL$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFURL.c"

$(IntermediateDirectory)/CFURLAccess$(ObjectSuffix): ../../CFURLAccess.c $(IntermediateDirectory)/CFURLAccess$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFURLAccess.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFURLAccess$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFURLAccess$(DependSuffix): ../../CFURLAccess.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFURLAccess$(ObjectSuffix) -MF$(IntermediateDirectory)/CFURLAccess$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFURLAccess.c"

$(IntermediateDirectory)/CFUserNotification$(ObjectSuffix): ../../CFUserNotification.c $(IntermediateDirectory)/CFUserNotification$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUserNotification.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFUserNotification$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFUserNotification$(DependSuffix): ../../CFUserNotification.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFUserNotification$(ObjectSuffix) -MF$(IntermediateDirectory)/CFUserNotification$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUserNotification.c"

$(IntermediateDirectory)/CFUtilities$(ObjectSuffix): ../../CFUtilities.c $(IntermediateDirectory)/CFUtilities$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUtilities.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFUtilities$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFUtilities$(DependSuffix): ../../CFUtilities.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFUtilities$(ObjectSuffix) -MF$(IntermediateDirectory)/CFUtilities$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUtilities.c"

$(IntermediateDirectory)/CFUUID$(ObjectSuffix): ../../CFUUID.c $(IntermediateDirectory)/CFUUID$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUUID.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFUUID$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFUUID$(DependSuffix): ../../CFUUID.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFUUID$(ObjectSuffix) -MF$(IntermediateDirectory)/CFUUID$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFUUID.c"

$(IntermediateDirectory)/CFVersion$(ObjectSuffix): ../../CFVersion.c $(IntermediateDirectory)/CFVersion$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFVersion.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFVersion$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFVersion$(DependSuffix): ../../CFVersion.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFVersion$(ObjectSuffix) -MF$(IntermediateDirectory)/CFVersion$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFVersion.c"

$(IntermediateDirectory)/CFWindowsMessageQueue$(ObjectSuffix): ../../CFWindowsMessageQueue.c $(IntermediateDirectory)/CFWindowsMessageQueue$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFWindowsMessageQueue.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFWindowsMessageQueue$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFWindowsMessageQueue$(DependSuffix): ../../CFWindowsMessageQueue.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFWindowsMessageQueue$(ObjectSuffix) -MF$(IntermediateDirectory)/CFWindowsMessageQueue$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFWindowsMessageQueue.c"

$(IntermediateDirectory)/CFXMLInputStream$(ObjectSuffix): ../../CFXMLInputStream.c $(IntermediateDirectory)/CFXMLInputStream$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLInputStream.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFXMLInputStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFXMLInputStream$(DependSuffix): ../../CFXMLInputStream.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFXMLInputStream$(ObjectSuffix) -MF$(IntermediateDirectory)/CFXMLInputStream$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLInputStream.c"

$(IntermediateDirectory)/CFXMLNode$(ObjectSuffix): ../../CFXMLNode.c $(IntermediateDirectory)/CFXMLNode$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLNode.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFXMLNode$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFXMLNode$(DependSuffix): ../../CFXMLNode.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFXMLNode$(ObjectSuffix) -MF$(IntermediateDirectory)/CFXMLNode$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLNode.c"

$(IntermediateDirectory)/CFXMLParser$(ObjectSuffix): ../../CFXMLParser.c $(IntermediateDirectory)/CFXMLParser$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLParser.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFXMLParser$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFXMLParser$(DependSuffix): ../../CFXMLParser.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFXMLParser$(ObjectSuffix) -MF$(IntermediateDirectory)/CFXMLParser$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLParser.c"

$(IntermediateDirectory)/CFXMLPreferencesDomain$(ObjectSuffix): ../../CFXMLPreferencesDomain.c $(IntermediateDirectory)/CFXMLPreferencesDomain$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLPreferencesDomain.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFXMLPreferencesDomain$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFXMLPreferencesDomain$(DependSuffix): ../../CFXMLPreferencesDomain.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFXMLPreferencesDomain$(ObjectSuffix) -MF$(IntermediateDirectory)/CFXMLPreferencesDomain$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLPreferencesDomain.c"

$(IntermediateDirectory)/CFXMLTree$(ObjectSuffix): ../../CFXMLTree.c $(IntermediateDirectory)/CFXMLTree$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLTree.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/CFXMLTree$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFXMLTree$(DependSuffix): ../../CFXMLTree.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/CFXMLTree$(ObjectSuffix) -MF$(IntermediateDirectory)/CFXMLTree$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/CFXMLTree.c"

$(IntermediateDirectory)/dirent$(ObjectSuffix): ../../compat/dirent.c $(IntermediateDirectory)/dirent$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/dirent.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/dirent$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dirent$(DependSuffix): ../../compat/dirent.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/dirent$(ObjectSuffix) -MF$(IntermediateDirectory)/dirent$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/dirent.c"

$(IntermediateDirectory)/flsl$(ObjectSuffix): ../../compat/flsl.c $(IntermediateDirectory)/flsl$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/flsl.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/flsl$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/flsl$(DependSuffix): ../../compat/flsl.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/flsl$(ObjectSuffix) -MF$(IntermediateDirectory)/flsl$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/flsl.c"

$(IntermediateDirectory)/gettimeofday$(ObjectSuffix): ../../compat/gettimeofday.c $(IntermediateDirectory)/gettimeofday$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/gettimeofday.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gettimeofday$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gettimeofday$(DependSuffix): ../../compat/gettimeofday.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/gettimeofday$(ObjectSuffix) -MF$(IntermediateDirectory)/gettimeofday$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/gettimeofday.c"

$(IntermediateDirectory)/strlcat$(ObjectSuffix): ../../compat/strlcat.c $(IntermediateDirectory)/strlcat$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/strlcat.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/strlcat$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/strlcat$(DependSuffix): ../../compat/strlcat.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/strlcat$(ObjectSuffix) -MF$(IntermediateDirectory)/strlcat$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/strlcat.c"

$(IntermediateDirectory)/strlcpy$(ObjectSuffix): ../../compat/strlcpy.c $(IntermediateDirectory)/strlcpy$(DependSuffix)
	@makedir "./Debug"
	$(CompilerName) $(SourceSwitch) "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/strlcpy.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/strlcpy$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/strlcpy$(DependSuffix): ../../compat/strlcpy.c
	@makedir "./Debug"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/strlcpy$(ObjectSuffix) -MF$(IntermediateDirectory)/strlcpy$(DependSuffix) -MM "C:/lal/openquartz/openquartz_20091227/openquartz/src/CoreFoundationLite/compat/strlcpy.c"

##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/CFApplicationPreferences$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFApplicationPreferences$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFApplicationPreferences$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFArray$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFArray$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFArray$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBag$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBag$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBag$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBase$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBase$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBase$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBinaryHeap$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBinaryHeap$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBinaryHeap$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBinaryPList$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBinaryPList$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBinaryPList$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBitVector$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBitVector$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBitVector$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBuiltinConverters$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBuiltinConverters$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBuiltinConverters$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBundle$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBundle$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBundle$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFBundle_Resources$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFBundle_Resources$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFBundle_Resources$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFCalendar$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFCalendar$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFCalendar$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFCharacterSet$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFCharacterSet$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFCharacterSet$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFConcreteStreams$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFConcreteStreams$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFConcreteStreams$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFData$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFData$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFData$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFDate$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFDate$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFDate$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFDateFormatter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFDateFormatter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFDateFormatter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFDictionary$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFDictionary$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFDictionary$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFError$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFError$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFError$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFFileDescriptor$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFFileDescriptor$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFFileDescriptor$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFFileUtilities$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFFileUtilities$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFFileUtilities$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFLocale$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFLocale$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFLocale$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFLocaleIdentifier$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFLocaleIdentifier$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFLocaleIdentifier$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFMachPort$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFMachPort$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFMachPort$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFMessagePort$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFMessagePort$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFMessagePort$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFNotificationCenter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFNotificationCenter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFNotificationCenter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFNumber$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFNumber$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFNumber$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFNumberFormatter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFNumberFormatter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFNumberFormatter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFPlatform$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFPlatform$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFPlatform$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_Factory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_Factory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_Factory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_Instance$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_Instance$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_Instance$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_PlugIn$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_PlugIn$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFPlugIn_PlugIn$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFPreferences$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFPreferences$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFPreferences$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFPropertyList$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFPropertyList$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFPropertyList$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFRunLoop$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFRunLoop$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFRunLoop$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFRuntime$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFRuntime$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFRuntime$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFSet$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFSet$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFSet$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFSocket$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFSocket$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFSocket$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFSocketStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFSocketStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFSocketStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFSortFunctions$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFSortFunctions$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFSortFunctions$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFStorage$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFStorage$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFStorage$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFString$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFString$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFString$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFStringEncodingConverter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFStringEncodingConverter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFStringEncodingConverter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFStringEncodings$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFStringEncodings$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFStringEncodings$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFStringScanner$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFStringScanner$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFStringScanner$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFStringUtilities$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFStringUtilities$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFStringUtilities$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFSystemDirectories$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFSystemDirectories$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFSystemDirectories$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFTimeZone$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFTimeZone$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFTimeZone$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFTree$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFTree$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFTree$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFUniChar$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFUniChar$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFUniChar$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFUnicodeDecomposition$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFUnicodeDecomposition$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFUnicodeDecomposition$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFUnicodePrecomposition$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFUnicodePrecomposition$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFUnicodePrecomposition$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFURL$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFURL$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFURL$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFURLAccess$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFURLAccess$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFURLAccess$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFUserNotification$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFUserNotification$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFUserNotification$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFUtilities$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFUtilities$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFUtilities$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFUUID$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFUUID$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFUUID$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFVersion$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFVersion$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFVersion$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFWindowsMessageQueue$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFWindowsMessageQueue$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFWindowsMessageQueue$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLInputStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLInputStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLInputStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLNode$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLNode$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLNode$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLParser$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLParser$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLParser$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLPreferencesDomain$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLPreferencesDomain$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLPreferencesDomain$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLTree$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLTree$(DependSuffix)
	$(RM) $(IntermediateDirectory)/CFXMLTree$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/dirent$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/dirent$(DependSuffix)
	$(RM) $(IntermediateDirectory)/dirent$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/flsl$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/flsl$(DependSuffix)
	$(RM) $(IntermediateDirectory)/flsl$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gettimeofday$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gettimeofday$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gettimeofday$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/strlcat$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/strlcat$(DependSuffix)
	$(RM) $(IntermediateDirectory)/strlcat$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/strlcpy$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/strlcpy$(DependSuffix)
	$(RM) $(IntermediateDirectory)/strlcpy$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)

-include $(IntermediateDirectory)/*$(DependSuffix)



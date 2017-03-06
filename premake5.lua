workspace "axFW"
	configurations	{ "Debug", "Release"	}
	platforms	{ "Win64"		}
   
	-- Windows x64 is now the _only_ supported platform
	-- There's far too much feature creep otherwise...
	system		"windows"
	architecture	"x86_64"
 
	-- Core bnrFW library
	project "CRT"
		targetdir	"../output"
		objdir		"../output"
		kind		"StaticLib"
		language	"C"

		sysincludedirs
		{
			"$(ProjectDir)", 
			"$(WindowsSdkDir_10)Include\\10.0.14393.0\\um"
		}

		files
		{
			"new",
			"**.h", 
			"**.c",
			"**.inl"
		}
		

		configuration "Debug"
			targetprefix	"Debug-"
			defines		"BNR_BUILD_DEBUG"
			optimize	"Off"
			symbols		"On"
			flags
			{
				"MultiProcessorCompile",
				"OmitDefaultLibrary",		-- We provide our own CRT		
			}
	 
		configuration "Release"
			targetprefix	"Release-"
			defines		"BNR_BUILD_NDEBUG"
			optimize	"Speed"
			flags
			{
				"MultiProcessorCompile",
				"OmitDefaultLibrary",
			
				"LinkTimeOptimization",
				"NoBufferSecurityCheck",
				"NoFramePointer",
				"NoManifest",
				"NoRuntimeChecks"					
			}
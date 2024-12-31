FILE(GLOB GAWER_SOURCE *.cpp)
target_sources(GAW-EngineExe PUBLIC 
	${GAWER_SOURCE}
)

target_sources(GAW-EngineLib PUBLIC ${GAWER_SOURCE})

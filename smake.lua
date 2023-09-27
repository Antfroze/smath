local import = import('smake/libraryInstaller')
import('smake/gpp', true)
local fs = import('smake/utils/fs')

function smake.build()
  if not fs.Exists("out") then
    fs.CreateFolder("out")
  end

  standard('c++2a')

  inputr('src')
  include('include')

  output('out/smath')
  build()

  smake.run()
end

function smake.run()
  run('out/smath')
end

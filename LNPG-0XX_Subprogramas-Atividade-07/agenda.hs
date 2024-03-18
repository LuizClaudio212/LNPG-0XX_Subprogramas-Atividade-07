import Data.List

-- Definição de tipos
type Evento = String
type Agenda = [Evento]

-- Função principal
main :: IO ()
main = do
    putStrLn "Bem-vindo ao Gerenciador de Agenda!"
    loop []

-- Função de loop para interação com o usuário
loop :: Agenda -> IO ()
loop agenda = do
    mostrarOpcoes
    opcao <- getOpcao
    executarOpcao opcao agenda

-- Função para mostrar as opções disponíveis
mostrarOpcoes :: IO ()
mostrarOpcoes = do
    putStrLn "\nSelecione uma opção:"
    putStrLn "1. Adicionar evento"
    putStrLn "2. Remover evento"
    putStrLn "3. Visualizar agenda"
    putStrLn "4. Sair"

-- Função para obter a opção do usuário
getOpcao :: IO String
getOpcao = getLine

-- Função para executar a opção escolhida pelo usuário
executarOpcao :: String -> Agenda -> IO ()
executarOpcao "1" agenda = adicionarEvento agenda
executarOpcao "2" agenda = removerEvento agenda
executarOpcao "3" agenda = visualizarAgenda agenda
executarOpcao "4" _      = putStrLn "Saindo do programa..."
executarOpcao _    agenda = do
    putStrLn "Opção inválida. Tente novamente."
    loop agenda

-- Função para adicionar um evento à agenda
adicionarEvento :: Agenda -> IO ()
adicionarEvento agenda = do
    putStrLn "Digite o evento a ser adicionado:"
    evento <- getLine
    let novaAgenda = agenda ++ [evento]
    loop novaAgenda

-- Função para remover um evento da agenda
removerEvento :: Agenda -> IO ()
removerEvento agenda = do
    putStrLn "Digite o nome do evento a ser removido:"
    nomeEvento <- getLine
    let novaAgenda = delete nomeEvento agenda
    loop novaAgenda

-- Função para visualizar todos os eventos na agenda
visualizarAgenda :: Agenda -> IO ()
visualizarAgenda agenda = do
    putStrLn "Eventos na Agenda:"
    mapM_ putStrLn agenda
    loop agenda

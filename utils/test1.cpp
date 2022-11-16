#include<iostream>
#include<vector>
#include<string>

using namespace  std;
class Game
{
public:
    void create( ) {
        cout << "Create game " << endl;
    }
    void open( string file ) {
        cout << "Open game from " << file << endl;
    }
    void save( string file ) {
        cout << "Save game in " << file << endl;
    }
    void make_move( string move ) {
        cout << "Make move " << move << endl;
    }
};

string getPlayerInput( string prompt ) {
    string input;
    cout << prompt;
    cin >> input;
    return input;
}

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
protected:
    Command( Game* p ): pgame( p) {}
    Game * pgame;
};

class CreateGameCommand: public Command
{
public:
    CreateGameCommand( Game * p ) : Command( p) {}
    void execute() {
        pgame->create( );
    }
};

class OpenGameCommand: public Command
{
public:
    OpenGameCommand( Game * p ) : Command( p) {}
    void execute() {
        string file_name;
        file_name = getPlayerInput( "Enter file name:");
        pgame->open( file_name);
    }
};

class SaveGameCommand: public Command
{
public:
    SaveGameCommand( Game * p ) : Command( p) {}
    void execute( ) {
        string file_name;
        file_name = getPlayerInput( "Enter file name:");
        pgame->save( file_name);
    }
};

class MakeMoveCommand: public Command
{
public:
    MakeMoveCommand( Game * p) : Command( p) {}
    void execute() {
        pgame->save( "TEMP_FILE");
        string move;
        move = getPlayerInput( "Enter your move:");
        pgame->make_move( move);
    }
};

class UndoCommand: public Command
{
public:
    UndoCommand( Game * p ) : Command( p) {}
    void execute() {
        pgame->open( "TEMP_FILE");
    }
};


int main()
{
    Game game;
    vector<Command*> v;
    v.push_back( new CreateGameCommand( &game));
    v.push_back( new MakeMoveCommand( &game));
    v.push_back( new MakeMoveCommand( &game));
    v.push_back( new UndoCommand( &game));
    v.push_back( new SaveGameCommand( &game));

    return 0;
}
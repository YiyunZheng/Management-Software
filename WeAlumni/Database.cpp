#include "Database.h"

/*
 * Database.h
 *
 * This file implements all Database interfaces.
 *
 * @author: Hang Yuan
 * Revised: 3/23/20
 *
 */

/*
 * GetDatabasePassword
 * This method will offer the corresponding password based on DatabaseType
 * @param None
 * @return String^ the password of target database
 */
System::String^ WeAlumni::Database::GetDatabasePassword() {
    if (_databaseType == DatabaseType::Admin) {
        return DB_ADMIN_PASSWORD;
    }
    else if (_databaseType == DatabaseType::Data) {
        return DB_DATA_PASSWORD;
    }
    else {
        return DB_TREASURY_PASSWORD;
    }
}

/*
 * SetPassword
 * This method will offer the name of database file by DatabaseType
 * @param None
 * @return String^ the name of current database
 */
System::String^ WeAlumni::Database::GetDatabaseName() {
    if (_databaseType == DatabaseType::Admin) {
        return DB_ADMIN_NAME;
    }
    else if (_databaseType == DatabaseType::Data) {
        return DB_DATA_NAME;
    }
    else {
        return DB_TREASURY_NAME;
    }
}

/*
 * CheckDatabaseFileExistence
 * This method will check if the database file exists in the destinated location
 * @param None
 * @return bool true if the file exists
 *              false if not
 */
bool WeAlumni::Database::CheckDatabaseFileExistence() {
    bool existence = false;
    if (System::IO::File::Exists(GetDatabaseName())) {
        existence = true;
    }
    return existence;
}

/*
 * GetConnectionString
 * This method will offer ConnectionString for DatabaseConnection to open a database file.
 * @param None
 * @return String^ the ConnectionString
 */
System::String^ WeAlumni::Database::GetConnectionString() {
    String^ connectionString = "Data Source = " + GetDatabaseName() + "; " +
                               "Password = " + GetDatabasePassword() + "; " +
                               "Read Only = " + _readOnly;
    return connectionString;
}

/*
 * CreateDatabaseFile
 * This method will create a new Database file, with password set in.
 * @param None
 * @return bool true if successfully create the file
 *              false if not
 */
bool WeAlumni::Database::CreateDatabaseFile() {
    bool success = false;
    try {
        String^ databaseName = GetDatabaseName();
        SQLiteConnection::CreateFile(databaseName);
        database = gcnew SQLiteConnection("Data Source = " + databaseName);
        database->SetPassword(GetDatabasePassword());
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return success;
}

/*
 * Initialize
 * This method will CheckDatabaseFileExistence first. If it goes well, it will open the database connection.
 * @param None
 * @return None
 * @exception customized exception or SQLiteException
 */
void WeAlumni::Database::Initialize() {
    if (!CheckDatabaseFileExistence()) {
        throw gcnew Exception("此数据库不存在或不在指定位置：" + GetDatabaseName());
    }

    try {
        database = gcnew SQLiteConnection(GetConnectionString());
        database->Open();
        command = database->CreateCommand();
    }
    catch (SQLiteException^ exception) {
        throw exception;
    }
}

/*
 * ReadData
 * This method will try to read the Database as the command given.
 * @param String^ command that will be executed
                  "SELECT [* or COLUMN_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
                  "SELECT [COLUMN_NAME] AS [NEW_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 * @return int -1 if nothing is read or catch an exception
 *             # of rows read if the execution is successful
 */
int WeAlumni::Database::ReadData(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
    command->CommandText = cmd;
    int rowRead = -1;
    try {
        dataReader = command->ExecuteReader();
        if (dataReader->Read()) {
            rowRead = dataReader->StepCount;
        }
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowRead;
}

/*
 * ReadDataAdapter
 * This method will try to read the Database as the command given.
 * @param String^ command that will be executed
 *                "SELECT [* or COLUMN_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 *                "SELECT [COLUMN_NAME] AS [NEW_NAME] FROM [TABLE_NAME] WHERE [CONDITION(s)];"
 * @return int -1 if catch an exception
 *             # of rows read if the execution is successful
 */
int WeAlumni::Database::ReadDataAdapter(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
	command->CommandText = cmd;
    int rowRead = -1;
	try {
		dataAdapter = gcnew SQLiteDataAdapter();
		dataAdapter->SelectCommand = command;
		dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);
        rowRead = dataTable->Rows->Count;
	}
	catch (SQLiteException^) {
        // Leave empty
	}
    return rowRead;
}

/*
 * InsertData
 * This method will try to insert data into the Database as the command given.
 * @param String^ command that will be executed
 *                "INSERT INTO [TABLE_NAME] VALUES ([DATA],[DATA],...);"
 *                "INSERT INTO [TABLE_NAME]([COLUMN_NAME], [COLUMN_NAME],...) VALUES ([DATA],[DATA],...);"
 * @return int -1 if catch an exception
 *             # of rows that are successfully inserted 
 */
int WeAlumni::Database::InsertData(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
    int rowInserted = -1;
    try {
        command->CommandText = cmd;
        rowInserted = command->ExecuteNonQuery();
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowInserted;
}

/*
 * InsertData
 * This method will try to insert data into the Database as the command given.
 * @param String^ command that will be executed
 *                "UPDATE [TABLE_NAME] SET [COLUMN_NAME] = [DATA], [COLUMN_NAME] = [DATA}, ... WHERE [CONDITION];"
 * @return int -1 if catch an exception
 *             # of rows that are successfully updated 
 */
int WeAlumni::Database::UpdateData(String^ cmd) {
    if (dataReader && !dataReader->IsClosed) dataReader->Close();
    int rowupdated = -1;
    try {
        command->CommandText = cmd;
        rowupdated = command->ExecuteNonQuery();
    }
    catch (SQLiteException^) {
        // Leave empty
    }
    return rowupdated;
}
USE [master]
GO
CREATE DATABASE [Lab4Countries]
GO
USE [Lab4Countries]
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Countries](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[NameK] [ntext] NULL,
	[NameG] [ntext] NULL,
	[NameS] [ntext] NULL,
	[Cheell] [ntext] NULL,
 CONSTRAINT [PK_Countries] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
USE [master]
GO
ALTER DATABASE [Lab4Countries] SET  READ_WRITE 
GO
